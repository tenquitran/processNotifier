#ifndef PROCESS_STATE_H
#define PROCESS_STATE_H

#include <string>


namespace ProcessNotifierApp
{
    enum class EProcessState
    {
        Undefined,
        Unknown,      /* empty character in /proc/<PID>/stat */
        Running,
        Sleeping,     /* sleeping in an interruptible wait */
        DiskSleep,    /* waiting in uninterruptible disk sleep */
        Zombie,
        StoppedOnSignal,
        TracingStop,
        Paging,
        Dead,
        Wakekill,
        Waking,
        Parked
    };
    
    
    class ProcessStateConverter
    {
    public:
        static EProcessState charToState(char c);
        
        static std::string stateToString(EProcessState state);
    };
}

#endif
