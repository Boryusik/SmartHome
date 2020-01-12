#include "mu_test.h"
#include <iostream>   

#include <pthread.h>

#include "Thread.h"
#include "Producer.h"
#include "ProducerNeg.h"
#include "ProducerPos.h"
#include "Consumer.h"
#include "WaitableQueue.h"
#include "VectorConsumer.h"
#include <vector>
#include <algorithm>


bool comprFun(int _lhs, int _rhs)
{
    return _lhs + 1 == _rhs;
}

using namespace advcpp;

UNIT(thread_1p_1c)
    WaitableQueue<int> wt;
    IRunnable * prod = new Producer<int>(&wt);
    IRunnable * cons = new Consumer<int>(&wt);
    Thread th1(prod);
    Thread th2(cons);

    th1.join();
    th2.join();

    ASSERT_EQUAL(wt.isEmpty(), true);
    ASSERT_THAT((static_cast<Consumer<int>* >(cons))->checkFifo() == true);
    
    delete prod;
    delete cons;

END_UNIT

// UNIT(thread_2p_1c)
//     WaitableQueue<int>wt;
//     IRunnable * prod1 = new ProducerNeg<int>(&wt,500000);
//     IRunnable * prod2 = new ProducerPos<int>(&wt,500000);
//     IRunnable * cons = new Consumer<int>(&wt,1000000);

//     Thread th1(prod1);
//     Thread th2(prod2);
//     Thread th3(cons);

//     th1.join();
//     th2.join();
//     th3.join();
    
//     ASSERT_EQUAL(wt.isEmpty(), true);
//     ASSERT_THAT((static_cast<Consumer<int>* >(cons))->checkFifo() == true);
   
//     delete prod1;
//     delete prod2;
//     delete cons;

// END_UNIT

// UNIT(thread_1p_2c)
//     WaitableQueue<int> wt;
//     IRunnable * prod1 = new Producer<int>(&wt,1000000);
//     IRunnable * cons1 = new Consumer<int>(&wt,500000);
//     IRunnable * cons2 = new Consumer<int>(&wt,500000);

//     Thread th1(prod1);
//     Thread th2(cons1);
//     Thread th3(cons2);

//     th1.join();
//     th2.join();
//     th3.join();

//     ASSERT_EQUAL(wt.isEmpty(), true);
//     ASSERT_THAT((static_cast<Consumer<int>* >(cons1))->checkFifo() == true);
//     ASSERT_THAT((static_cast<Consumer<int>* >(cons2))->checkFifo() == true);
//     delete prod1;
//     delete cons1;
//     delete cons2;

// END_UNIT

// UNIT(thread_2p_2c)
//     WaitableQueue<int> wt;
//     IRunnable * prod1 = new ProducerNeg<int>(&wt,800000);
//     IRunnable * prod2 = new ProducerPos<int>(&wt,200000);
//     IRunnable * cons1 = new Consumer<int>(&wt,600000);
//     IRunnable * cons2 = new Consumer<int>(&wt,400000);


//     Thread th1(prod1);
//     Thread th2(prod2);
//     Thread th3(cons1);
//     Thread th4(cons2);

//     th1.join();
//     th2.join();
//     th3.join();
//     th4.join();

//     ASSERT_EQUAL(wt.isEmpty(), true);
//     ASSERT_THAT((static_cast<Consumer<int>* >(cons1))->checkFifo() == true);
//     ASSERT_THAT((static_cast<Consumer<int>* >(cons2))->checkFifo() == true);

//     delete prod1;
//     delete prod2;
//     delete cons1;
//     delete cons2;

// END_UNIT

// UNIT(thread_2p_2c_corect_removing)
//     WaitableQueue<int> wt;
//     IRunnable * prod1 = new ProducerNeg<int>(&wt,5);
//     IRunnable * prod2 = new ProducerPos<int>(&wt,5);
//     IRunnable * cons1 = new VectorConsumer<int>(&wt,5);
//     IRunnable * cons2 = new VectorConsumer<int>(&wt,5);


//     Thread th1(prod1);
//     Thread th2(prod2);
//     Thread th3(cons1);
//     Thread th4(cons2);

//     th1.join();
//     th2.join();
//     th3.join();
//     th4.join();

//     ASSERT_EQUAL(wt.isEmpty(), true);
//     ASSERT_THAT((static_cast<VectorConsumer<int>* >(cons1))->checkFifo() == true);
//     ASSERT_THAT((static_cast<VectorConsumer<int>* >(cons2))->checkFifo() == true);

    

//     std::vector<int> summaryVec;
//     size_t sizeOfvecCons1 = (static_cast<VectorConsumer<int>* >(cons1))->vector().size();
//     size_t sizeOfvecCons2 = (static_cast<VectorConsumer<int>* >(cons2))->vector().size();
//     summaryVec.reserve(sizeOfvecCons1 + sizeOfvecCons2);
        
//     summaryVec.insert(
//                    summaryVec.end()
//                   ,(static_cast<VectorConsumer<int>* >(cons1))->vector().begin()
//                   ,(static_cast<VectorConsumer<int>* >(cons1))->vector().end()
//                     );
//     summaryVec.insert(
//                    summaryVec.end()
//                   ,(static_cast<VectorConsumer<int>* >(cons2))->vector().begin()
//                   ,(static_cast<VectorConsumer<int>* >(cons2))->vector().end()
//                   );

//     std::sort(summaryVec.begin(), summaryVec.end());
//     ASSERT_THAT(std::equal(summaryVec.begin(), summaryVec.end() - 1, summaryVec.begin() + 1, comprFun));

//     delete prod1;
//     delete prod2;
//     delete cons1;
//     delete cons2;

// END_UNIT

TEST_SUITE(therad_test)

	TEST(thread_1p_1c)
    // TEST(thread_2p_1c)
    // TEST(thread_1p_2c)
    // TEST(thread_2p_2c)
    // TEST(thread_2p_2c_corect_removing)
  	
END_SUITE
