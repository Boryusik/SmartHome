#include "CondVar.h"
#include "cassert"
#include "cerrno"



namespace advcpp{
    CondVar::CondVar(Mutex* _mutex)
    :  m_conditVar()
    ,  m_mutex(_mutex)
    {
       pthread_cond_init(&m_conditVar, NULL);  
      
    }

    CondVar::~CondVar()   
    {
        pthread_cond_destroy(&m_conditVar);
       
    }


    

    void CondVar::signal()
    {
        pthread_cond_signal(&m_conditVar);   
    }

    pthread_cond_t & CondVar::conditionVar()
    {
        return m_conditVar;
    }

}