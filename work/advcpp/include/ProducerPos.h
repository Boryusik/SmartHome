#ifndef PRODUCER_POS_H
#define PRODUCER_POS_H

#include "Runnable.h"
#include "WaitableQueue.h"
#include "Mutex.h"

namespace advcpp{
    template <typename T>
    class ProducerPos: public IRunnable
    {
        public:
            ProducerPos(WaitableQueue<T>* const a_wq, size_t a_counter = 1000000);
           ~ProducerPos();
            void run();

        private:
            size_t              m_counter;
            WaitableQueue<T>*   m_queue;
    };


    template <typename T>
    ProducerPos<T>::ProducerPos(WaitableQueue<T>* const a_wq, size_t a_counter)
    :m_counter(a_counter)
    ,m_queue(a_wq)   
    {

    }

    template <typename T>
    ProducerPos<T>::~ProducerPos()
    {
        
    }

    template <typename T>
    void ProducerPos<T>::run()
    {
        for(size_t i = 0; i< m_counter; ++i)
        {
            m_queue->enqueue(i);
            // std::cout<< "produced i = "<< i<< '\n';
        }
    }
}

#endif