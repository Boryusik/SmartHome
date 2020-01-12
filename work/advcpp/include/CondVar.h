#ifndef COND_VAR_H
#define COND_VAR_H


#include <pthread.h> 
#include "Mutex.h"
#include <iostream>

namespace advcpp{
    class CondVar
    {
        public:            
            CondVar(Mutex* _mut);
            ~CondVar();            
            template <typename Predicate>            
            void wait(Predicate p);

            void signal();
            pthread_cond_t& conditionVar();
        private:
            pthread_cond_t  m_conditVar;
            Mutex*          m_mutex;
    };


    template <typename Predicate >
    void CondVar::wait(Predicate p)
    {
        while(p())
        {
            pthread_cond_wait(&m_conditVar, &m_mutex->m_locker); 
            // std::cout << "\n you'r in conditional \n";
        }               
    }
}

#endif