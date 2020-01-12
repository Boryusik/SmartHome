#ifndef VECTOR_CONSUMER_H
#define VECTOR_CONSUMER_H


#include <vector>
#include "WaitableQueue.h"
#include "Runnable.h"
namespace advcpp{
template <typename T>
class VectorConsumer: public IRunnable
{

public:
    VectorConsumer(WaitableQueue<T>* const a_wq, size_t a_count = 1000000);
    ~VectorConsumer();
    void run();
    bool checkFifo() const;
    const std::vector<T>& vector() const;

private:
    size_t              m_counter;
    WaitableQueue<T>*   m_queue;
    bool                m_isFifo;
    std::vector<T>      m_deqVec;     
};


template <typename T>
VectorConsumer<T>::VectorConsumer(WaitableQueue<T>* const a_wq, size_t a_count)
:m_counter(a_count)
,m_queue(a_wq)
,m_isFifo(true)
{

}

template <typename T>
VectorConsumer<T>::~VectorConsumer()
{    
}

template <typename T>
void VectorConsumer<T>::run()
{
    T item;
    int prev;
    for(size_t i = 0; i < m_counter; ++i)
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
            m_deqVec.push_back(item);
    }
}

template <typename T>
const std::vector<T>& VectorConsumer<T>::vector() const
{
    return m_deqVec;
}


template <typename T>
bool VectorConsumer<T>::checkFifo() const
{
    return m_isFifo;
}
}

#endif