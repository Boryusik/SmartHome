#ifndef PRODUCER_H
#define PRODUCER_H

#include "Runnable.h"
#include "WaitableQueue.h"
#include "Mutex.h"

namespace advcpp{
    template <typename T>
    class Producer: public IRunnable
    {
        public:
            Producer(WaitableQueue<T>* const a_wq, size_t a_counter = 1000000);
           ~Producer();
            void run();

        private:
            size_t              m_counter;
            WaitableQueue<T>*   m_queue;
    };


    template <typename T>
    Producer<T>::Producer(WaitableQueue<T>* const a_wq, size_t a_counter)
    :m_counter(a_counter)
    ,m_queue(a_wq)   
    {

    }

    template <typename T>
    Producer<T>::~Producer()
    {
        
    }

    template <typename T>
    void Producer<T>::run()
    {
        for(size_t i = 0; i< m_counter; ++i)
        {
            m_queue->enqueue(i);
            // std::cout<< "produced i = "<< i<< '\n';
        }
    }
}

#endif