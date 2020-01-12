#include "Mutex.h"
#include "cassert"
#include "cerrno"



namespace advcpp{
    Mutex::Mutex()
    {
        pthread_mutex_init(&m_locker, NULL);
    }

    Mutex::~Mutex()   
    {
        int e;
        e = pthread_mutex_destroy(&m_locker);
        assert(e != EBUSY);
        assert(e != EINVAL);
    }

    void Mutex::Lock()
    {
        int e;
        e = pthread_mutex_lock(&m_locker);
        assert(e != EBUSY);
        assert(e != EINVAL);
    }

    void Mutex::UnLock()
    {
        int e;
        e = pthread_mutex_unlock(&m_locker);
        assert(e != EBUSY);
        assert(e != EINVAL);
    }


    
    Mutex::Locker::Locker(Mutex &a_mtx)
    :m_mtx(a_mtx)
    { 
        m_mtx.Lock();
    }

    Mutex::Locker::~Locker()
    {
        m_mtx.UnLock();
    }

   
}