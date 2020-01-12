#include "Thread.h"
namespace advcpp
{
    // Thread::Thread()
    // :isJoined(false)
    // ,isDetached(false)
    // {

    // }

    // Thread::Thread(IRunnable  *r)
    // :isJoined(false)
    // ,isDetached(false)
    // {
    //     pthread_create(&m_thread, 0, Thread::start, r);
    // }

    // Thread::Thread(SharedPtr<IRunnable>  r)
    // :isJoined(false)
    // ,isDetached(false)
    // ,m_run(r)
    // {
    //     pthread_create(&m_thread, 0, Thread::start, this);
    // }

    Thread::Thread(IRunnable &r)
    :isJoined(false)
    ,isDetached(false)
    ,m_run(r)
    {
        // pthread_create(&m_thread, 0, Thread::start, &r);
        pthread_create(&m_thread, 0, Thread::start, this);
    }


    Thread::Thread(SharedPtr<IRunnable> r)
    :isJoined(false)
    ,isDetached(false)
    ,m_run(*r)
    {
        pthread_create(&m_thread, 0, Thread::start, this);
    }

    Thread::~Thread()
    {

    }

    void Thread::join()
    {
        if(!isJoined)
        {
             pthread_join(m_thread, 0);
             isJoined = true;            
        }
       
    }

    bool Thread::operator== (pthread_t const& _rhs )
    {
        return m_thread == _rhs;

    }

    void Thread::detach()
    {
        if(!isDetached)
        {
             pthread_detach(m_thread);
             isDetached = true;             
        }
       
    }

    void* Thread::start(void *p)
    {
        Thread* self = static_cast<Thread*>(p); 
        self->m_run.run();

        return 0;
    }
}

