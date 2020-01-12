#ifndef CONSUMER_H
#define CONSUMER_H

#include "Runnable.h"
#include "WaitableQueue.h"

namespace advcpp{
    template <typename T>
    class Consumer: public IRunnable
    {
        public:
            Consumer(WaitableQueue<T>* const m_queue, size_t a_count = 1000000);
            ~Consumer();
            void run();
            bool checkFifo() const;
        private: 
            size_t              m_counter;
            WaitableQueue<T>*   m_queue;
            bool                m_isFifo;

    };


    template <typename T>
    Consumer<T>::Consumer(WaitableQueue<T>* const a_wq, size_t a_count)
    :m_counter(a_count)
    ,m_queue(a_wq)
    ,m_isFifo(true)
    {

    }

    template <typename T>
    Consumer<T>::~Consumer()
    {
        
    }

    template <typename T>
    void Consumer<T>::run()
    {
        int item;
        int prev;
        for(size_t i = 0; i< m_counter; ++i)
        {
            if(i == 0)
            {
                prev = 0;
                m_queue->dequeue(item);
                continue;
            }
             m_queue->dequeue(item);
             if((item>0 && item <= prev) || (item<0 && item >= prev) )
             {
                 m_isFifo = false;
             }
            prev = item;
            // prev = static_cast<int>(i);
            //  std::cout<< "consumed item = "<< item << '\n';
        }
    }

    template <typename T>
    bool Consumer<T>::checkFifo() const
    {
        return m_isFifo;
    }

}
#endif