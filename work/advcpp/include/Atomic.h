#ifndef ATOMIC_H
#define ATOMIC_H

template <typename T>
class AtomicVal
{
    public:
        //AtomicVal() ; //defult
        AtomicVal(T const& _a);
        AtomicVal(AtomicVal<T> const& _other);
	AtomicVal<T>& operator =(AtomicVal<T> const& _rhs);
        AtomicVal<T>& operator ++();
        AtomicVal<T> operator ++(int);
        AtomicVal<T>& operator --();
        AtomicVal<T> operator --(int);
        AtomicVal<T>& operator += (AtomicVal<T> const& _rhs); 
        AtomicVal<T>& operator -= (AtomicVal<T> const& _rhs); 
        bool operator == (AtomicVal<T> const& a_val); 
        bool operator != (AtomicVal<T> const& a_val); 
        
        operator T() const;
        T value() const;

    private:
        T m_val;     

};

template <typename T>
AtomicVal<T>::AtomicVal(T const& _a)
:m_val(_a)
{

}

template<typename T>
AtomicVal<T>::AtomicVal(AtomicVal<T> const& _other)
:m_val(_other.m_val)
{
}

template<typename T>
AtomicVal<T>& AtomicVal<T>::operator =(AtomicVal<T> const& _rhs)
{
   m_val = _rhs.m_val;
   return *this;
}

template <typename T>
AtomicVal<T>& AtomicVal<T>::operator ++()
{
    __sync_add_and_fetch (&m_val, 1);
    
    return *this;

}

template <typename T>
AtomicVal<T> AtomicVal<T>::operator ++(int)
{
    
    AtomicVal<T> temp(*this);
    __sync_fetch_and_add(&m_val, 1);
    return temp;
}

template <typename T>
AtomicVal<T>& AtomicVal<T>::operator --()
{
    __sync_sub_and_fetch (&m_val, 1);
    return *this;
}

template <typename T>
AtomicVal<T> AtomicVal<T>::operator --(int)
{
    AtomicVal<T> temp(*this);   
    __sync_fetch_and_sub(&m_val, 1);
    return temp;

}

template <typename T>
AtomicVal<T>& AtomicVal<T>::operator += (AtomicVal<T> const& _rhs)
{
    // m_val += _rhs.m_val;
    __sync_fetch_and_add(&m_val, _rhs.value());
    return *this;
}


template <typename T>
AtomicVal<T>& AtomicVal<T>::operator -= (AtomicVal<T> const& _rhs)
{
    __sync_fetch_and_sub(&m_val, _rhs.value());
    return *this;
} 

template <typename T>
bool AtomicVal<T>::operator == (AtomicVal<T> const& _rhs)
{
    return (value() == _rhs.value());
}

template <typename T>
bool AtomicVal<T>::operator != (AtomicVal<T> const& _rhs)
{
    return !(*this==_rhs);
}

template <typename T>
T AtomicVal<T>::value() const
{
    return __sync_fetch_and_add(const_cast<T*>(&m_val), 0);
}

template <typename T>
AtomicVal<T>::operator T() const
{
    return value();
}

#endif
