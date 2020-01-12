#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h> 
class CondVar;

namespace advcpp{
    class  Mutex
    {
        public:
        class Locker{
        public:
            Locker(Mutex& a_mtx);
            ~Locker();

        private:
           Mutex& m_mtx;

    };

            friend class CondVar;
            Mutex();
            ~Mutex();
            void Lock();
            void UnLock();
            
        private:
            pthread_mutex_t* locker() const;
            pthread_mutex_t m_locker;

    };

    
}
#endif