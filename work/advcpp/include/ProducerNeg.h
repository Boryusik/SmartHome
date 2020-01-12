#ifndef PRODUCER_NEG_H
#define PRODUCER_NEG_H

#include "Runnable.h"
#include "WaitableQueue.h"
#include "Mutex.h"

namespace advcpp{
    template <typename T>
    class ProducerNeg: public IRunnable
    {
        public:
            ProducerNeg(WaitableQueue<T>* const a_wq, size_t a_counter = 1000000);
           ~ProducerNeg();
            void run();

        private:
            size_t              m_counter;
            WaitableQueue<T>*   m_queue;
    };


    template <typename T>
    ProducerNeg<T>::ProducerNeg(WaitableQueue<T>* const a_wq, size_t a_counter)
    :m_counter(a_counter)
    ,m_queue(a_wq)   
    {

    }

    template <typename T>
    ProducerNeg<T>::~ProducerNeg()
    {
        
    }

    template <typename T>
    void ProducerNeg<T>::run()
    {
        for(size_t i = 1; i<= m_counter; ++i)
        {
            m_queue->enqueue(-i);
            // std::cout<< "produced i = "<< i<< '\n';
        }
    }
}

#endif