#ifndef BASE_H
#define BASE_H

#include <iostream>

class B{
    public:
        virtual int fx() {std::cout<< "fx was called" <<'\n'; return 1;}
        virtual int fz() {std::cout<< "fz was called" <<'\n'; return 1;}
};

class A : public B{
    public:
    A(B* _b):B(){ fx();}
    A(B _b):B(){ fz();}
    
};



#endif