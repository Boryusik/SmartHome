#include "Cat.h"

// size_t Cat::catCounter = 0;

Cat::Cat()
:m_name("murzik")
{
    // ++Cat::catCounter;

}

Cat::Cat(std::string a_name)
:m_name(a_name)
{

}

Cat& Cat::operator= (Cat const& _otherCat)
{
    this->m_name = _otherCat.m_name;
    return *this;
}

void Cat::talk() const
{
    std::cout<< "Cat " << m_name << " said 'WAFF-WAFF'\n";
}

SiamesCat::SiamesCat()
:Cat()
{

}

SiamesCat::SiamesCat(std::string a_name)
:Cat(a_name)
{

}

std::ostream& operator <<(std::ostream& a_os, Cat const& a_cat)
{
    return a_os<<a_cat.NAME();
}