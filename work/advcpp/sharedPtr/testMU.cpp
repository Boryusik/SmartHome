#include "mu_test.h"
#include <iostream>   

#include <pthread.h>

#include "SharedPtr.h"
#include "Counter.h"
#include "Cat.h"



using namespace advcpp;

UNIT(shared_pointer)
    // Cat cat;
    SharedPtr<Cat> ptr1(new Cat);
    SharedPtr<Cat> ptr2(new Cat);
    SharedPtr<Cat> ptr3(ptr1);
    SharedPtr<Cat> ptr4(ptr1);
    SharedPtr<Cat> ptr5(ptr1);

    ASSERT_EQUAL(ptr3.counter(), 4);

    std::cout << "counter of pointers to Cat1 before is: "<<ptr3.counter() << '\n';
    std::cout << "counter of pointers to Cat2 before is: "<<ptr2.counter() << '\n';
    ptr1 = ptr2;
    std::cout << "counter of pointers to Cat1 after is: "<<ptr3.counter() << '\n';
    std::cout << "counter of pointers to Cat2 after is: "<<ptr2.counter() << '\n';

    

    ptr2 = ptr3;
    ptr1 = ptr3;

    std::cout << "counter of pointers to Cat1 after is: "<<ptr3.counter() << '\n';
    std::cout << "counter of pointers to Cat2 after is: "<<ptr2.counter() << '\n';


    SharedPtr<Cat> ptr6(new Cat);
    SharedPtr<Cat> ptr7(new SiamesCat);
    SharedPtr<SiamesCat> ptr8(new SiamesCat);
std::cout << "\ncounter of pointers to Cat  is: "<<ptr6.counter() << '\n';
    std::cout << "counter of pointers to SiamesCat  is: "<<ptr7.counter() << '\n';

    ptr6 = ptr7;
    ptr7 = ptr8;
    std::cout << "\ncounter of pointers to Cat after is: "<<ptr6.counter() << '\n';
    std::cout << "counter of pointers to SiamesCat  after is: "<<ptr7.counter() << '\n';

END_UNIT


TEST_SUITE(therad_test)

	TEST(shared_pointer)
    
  	
END_SUITE
