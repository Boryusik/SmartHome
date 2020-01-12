#ifndef THREADK_H
#define THREADK_H

#include <pthread.h>
#include "Runnable.h"
#include "SharedPtr.h"

// #include <tr1/memory>
// #define SharedPtr std::tr1::shared_ptr

namespace advcpp{   

      class Thread{
      public:
         // Thread();
         // Thread(IRunnable *r);
         Thread(IRunnable &r);
         Thread(SharedPtr<IRunnable> r);
         bool operator== (pthread_t const& _rhs );

         virtual ~Thread();
         void join();
         void detach();

         
      private:         
         static void* start(void *p);         
  
      private:         
         pthread_t m_thread;         
         bool isJoined;
         bool isDetached;
         IRunnable& m_run;
   };
}


#endif

