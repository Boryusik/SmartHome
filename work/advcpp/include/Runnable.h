#ifndef RUNNABLE_H
#define RUNNABLE_H

namespace advcpp{
    class IRunnable
    {
        public:
        virtual ~IRunnable() {};
        virtual void run() = 0; 
    };
}

#endif
