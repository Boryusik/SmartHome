#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include "Counter.h"

namespace advcpp{
template <typename T>
class SharedPtr
{
    public:
    explicit SharedPtr(T* _object = 0);
    SharedPtr(SharedPtr<T> const& _other);

    template <typename D >
    SharedPtr(SharedPtr<D> const& _other);

    ~SharedPtr();
    SharedPtr<T>& operator= (SharedPtr<T> const& _other);

    template <typename D >
    SharedPtr<T>& operator= (SharedPtr<D> const& _other);

    bool operator ==(SharedPtr<T> const& _other);
    bool operator !=(SharedPtr<T> const& _other);

    T* operator-> ();
    T& operator* ();
    size_t counter() const;
    bool operator!(){return m_ptr == 0;}
    
    private:
    void swap(SharedPtr<T>& _a, SharedPtr<T>& _b);

    private:
        template <typename D >
        // friend class SharedPtr<T>;
        friend class SharedPtr;
        
        T*       m_ptr;
        Counter* m_counter;
};

template <typename T>
SharedPtr<T>::SharedPtr(T* _object)
:m_ptr(_object)
{
    try{
        m_counter = new Counter(1);
    }
    catch(...){
        delete m_ptr;
        throw;
    }
    // m_counter = new Counter();
    // ++(*m_counter);
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> const& _other)
:m_ptr(_other.m_ptr)
,m_counter(_other.m_counter)
{
    ++(*m_counter);
}

template <typename T>
template <typename D>
SharedPtr<T>::SharedPtr(SharedPtr<D> const& _other)
:m_ptr(_other.m_ptr)
,m_counter(_other.m_counter)
{    
    ++(*m_counter);
}



template <typename T>
void SharedPtr<T>::swap(SharedPtr<T>& _a, SharedPtr<T>& _b)
{
    std::swap(_a.m_counter,_b.m_counter);
    std::swap(_a.m_ptr,_b.m_ptr);
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T> const& _other)
{
    SharedPtr<T> copy(_other);
    swap(*this, copy);
    // if(*m_counter == 1)
    // {
    //     delete m_counter;
    //     delete m_ptr;
    // }
    // else
    // {
    //     --*m_counter
    // }
    
    // m_ptr = _other.m_ptr;
    //  ++(*m_counter);
    // m_counter = _other.m_counter;
   
    return *this;
}


template <typename T>
template <typename D>
SharedPtr<T>& SharedPtr<T>::operator= (SharedPtr<D> const& _other)
{
    SharedPtr<T> copy(_other);
    swap(*this, copy);
    return *this;  
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if(*m_counter == 1)
    {
        delete m_counter;
        delete m_ptr;
    }
    else
    {
        --*m_counter;
    }
}

template <typename T>
bool SharedPtr<T>::operator== (SharedPtr<T> const& _other)
{
    return (m_ptr == _other.m_ptr);
}

template <typename T>
bool SharedPtr<T>::operator!= (SharedPtr<T> const& _other)
{
    return !(*this==_other);
}

template <typename T>
T* SharedPtr<T>::operator-> ()
{
    return m_ptr;
}


template <typename T>
T&  SharedPtr<T>::operator* ()
{
    return *m_ptr;
}



template <typename T>
size_t SharedPtr<T>::counter() const
{
    return m_counter->value();
}

}

#endif