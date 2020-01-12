#include "Counter.h"
namespace advcpp{

Counter::Counter(size_t a_val)
:m_val(a_val)
{

}

Counter::Counter(Counter const& _other)
:m_val(_other.m_val)
{
}


Counter::~Counter()
{

}

Counter& Counter::operator++()
{
    __sync_add_and_fetch (&m_val, 1);
   
    return *this;
}

Counter Counter::operator++ (int )
{
    Counter temp(*this);
   __sync_fetch_and_add (&m_val, 1);
   
    return temp;
}

Counter& Counter::operator--()
{
    __sync_sub_and_fetch (&m_val, 1);
    
    return *this;
}

Counter Counter::operator--(int )
{
    Counter temp(*this);
    __sync_fetch_and_sub (&m_val, 1);
   
    return temp;
}


bool Counter::operator == (size_t _rhs)
{
    return (value() == _rhs);
}

bool Counter::operator != (size_t _rhs)
{
    return !(*this==_rhs);
}


size_t Counter::value() const
{
    return __sync_fetch_and_add(const_cast<size_t*>(&m_val), 0);
}


}
