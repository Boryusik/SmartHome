#ifndef INCREMENT_H
#define INCREMENT_H

#include <iostream>
#include "Atomic.h"

template <typename T>
class AtomicIncrementor
{
    public:
        AtomicIncrementor(size_t a_inc = 1, T const& a_val = 0);
        AtomicIncrementor(AtomicVal<T> const& a_val, size_t a_inc = 1);
        T value() const;
        static void* IncrementTask(void* p);
        void inc();
    private:
       size_t        m_inc;
       AtomicVal<T>  m_val;
};


template <typename T>
class Incrementor
{
    public:
        Incrementor(size_t a_inc = 1, T const& a_val = 0);
        static void* IncrementTask(void* p);
        void inc();
        T const& value() const;

    private:
        size_t        m_inc;
        T             m_val;
        spex::Mutex   m_locker;
};

///////////////// Atomic Incrementor ////////////////////////////
template<typename T>
AtomicIncrementor<T>::AtomicIncrementor(size_t a_inc, T const& a_val)
: m_inc(a_inc)
, m_val(a_val)
{

}

template<typename T>
AtomicIncrementor<T>::AtomicIncrementor(AtomicVal<T> const& a_val, size_t a_inc)
: m_inc(a_inc)
, m_val(a_val)
{

}


template<typename T>
T AtomicIncrementor<T>::value() const
{
    return m_val.value();
}


template<typename T>
void AtomicIncrementor<T>::inc()
{
    for(size_t i = 0; i < m_inc; ++i)
    {
        ++m_val;
    }
}

template <typename T>
void* AtomicIncrementor<T>::IncrementTask(void* _p)
{
    AtomicIncrementor<T> *self = static_cast<AtomicIncrementor<T>* >(_p);
    self->inc();
    return 0;
}


/////////////////////// Incrementor //////////////////////
template<typename T>
Incrementor<T>::Incrementor(size_t a_inc, T const& a_val)
: m_inc(a_inc)
, m_val(a_val)
{

}

template<typename T>
void Incrementor<T>::inc()
{
    for(size_t i = 0; i < m_inc; ++i)
    {
        m_locker.Lock();
            ++m_val;
        m_locker.UnLock();
    }
}

template<typename T>
T const& Incrementor<T>::value() const
{
    return m_val;
}

template<typename T>
void* Incrementor<T>::IncrementTask(void* _p)
{
    Incrementor<T>* self = static_cast<Incrementor<T>*>(_p);
    self->inc();
    return 0;
}


#endif