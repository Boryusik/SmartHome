#ifndef CAT_H
#define CAT_H

#include <iostream>

class Cat{
    public:
        Cat();
        Cat(std::string a_name);
        Cat& operator=(Cat const& _otherCat);
        void talk() const;
        std::string const& NAME() const {return m_name;}
    private:
       std::string m_name;
       static size_t catCounter;

};


class SiamesCat : public Cat
{
    public:
    SiamesCat();
    SiamesCat(std::string a_name);
};

std::ostream& operator <<(std::ostream& a_os, Cat const& a_cat);

#endif