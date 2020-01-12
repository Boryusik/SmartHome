#include "mu_test.h"
#include "ThreadPoolExecutor.h"


class printer: public advcpp::IRunnable
{
public:
    printer(int a_from, int a_to) :m_from(a_from), m_to(a_to){};

    virtual void run(){
        for(int i = m_from; i < m_to; ++i)
        {
            m_res+=i;
        }
    };

    int result() const { return m_res;};

private:
    int m_res;
    int m_from;
    int m_to;
};


UNIT(create)

    //int const size = 10;
    advcpp::ThreadPoolExecutor t(3);

    advcpp::SharedPtr<printer> p(new printer(0, 5));
    advcpp::SharedPtr<printer> p2(new printer(20, 24));
 
    t.submit(p);
    t.submit(p2);
    t.addWorkers(3);
    t.shutDown();

    ASSERT_EQUAL(p->result(), 10);
    ASSERT_EQUAL(p2->result(), 86);
    

END_UNIT

TEST_SUITE(Thread pool test)

    TEST(create)


END_SUITE