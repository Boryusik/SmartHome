#ifndef COUNTER_H
#define COUNTER_H

#include <iostream>

namespace advcpp{
class Counter
{
    public:
  
        Counter(size_t a_val = 0);
        Counter(Counter const& _other);
        ~Counter();
        Counter& operator ++();
        Counter operator ++(int);
        Counter& operator --();
        Counter operator --(int);
        bool operator == (size_t a_val); 
        bool operator != (size_t a_val); 
        
        // operator Counter() const;
        size_t value() const;

    private:
        size_t m_val;     

};
}



#endif