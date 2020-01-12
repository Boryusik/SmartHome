#ifndef WAITABLE_H
#define WAITABLE_H

#include <queue>
#include <pthread.h> 
#include "Mutex.h"
#include "CondVar.h"
#include <cassert>

namespace advcpp{
    template <typename T>
    class WaitableQueue
    {
    public:
        WaitableQueue();
        void enqueue(T const& _item);
        void dequeue(T& _item);
        size_t size() const;
        bool isEmpty() const;
        bool empty() const;
        private:
        

    private:
    mutable Mutex           m_locker;
            CondVar         m_condit;
            std::queue<T>   m_queue;
        
    };  

    template <typename T>
    class IsEmpty
    {
        public:
            IsEmpty(WaitableQueue<T> const& a_wq);
             bool operator()() const;
        private:
           
            WaitableQueue<T>const & m_wq;

    };


    template <typename T>
    IsEmpty<T>::IsEmpty(WaitableQueue<T> const& a_wq)
    :m_wq(a_wq)
    {

    }


    template <typename T>
    bool IsEmpty<T>::operator()() const    
    {
        return m_wq.empty();
    }



    template <typename T>
    WaitableQueue<T>::WaitableQueue()
    : m_condit(&m_locker)
    {
        pthread_cond_init(&m_condit.conditionVar(), NULL);
    }


    template <typename T>
    void WaitableQueue<T>::enqueue(T const& _item)
    {        
            {
                Mutex::Locker lock(m_locker);
                m_queue.push(_item);
            
            m_condit.signal();   	
            }
   
    }

    template <typename T>
    void WaitableQueue<T>::dequeue(T& _item)
    {
        const IsEmpty<T> predicate(*this);        
        {
            Mutex::Locker lock(m_locker);
            m_condit.wait(predicate);
            _item = m_queue.front();
            m_queue.pop();
        }  
     
    }

    template <typename T>
    size_t WaitableQueue<T>::size() const
    {
        size_t size;      
        {
            Mutex::Locker lock(m_locker);
            size =  m_queue.size();
        }           
      
        return size;
    }

    template <typename T>
    bool WaitableQueue<T>::isEmpty() const
    {
        bool is_empty;       
        {   
            Mutex::Locker lock(m_locker);
            is_empty = empty();
        } 

        return is_empty;
    }

    template <typename T>
    bool WaitableQueue<T>::empty() const
    {
        return m_queue.empty();
    }
}

#endif