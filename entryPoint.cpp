#include <time.h>
#include <stdio.h>
#include <iostream>
#include "ProcessInfo.h"
#include "ProcessReader.h"
#include "ProcessAnalyzer.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////


int main(int argc, char* argv[])
{  
#if 0
    ProcessReader reader;
    
    // TODO: test
    
    Processes proc = reader.getInfo();
#if 0
    std::cout << "Process count: " << proc.size() << '\n' << std::endl;
    for (const auto& itr : proc)
    {
        std::cout << itr.m_pid << ": " << itr.m_path 
                  << " (" << ProcessStateConverter::stateToString(itr.m_state) << ")" << '\n';
    }
    std::cout << std::endl;
#endif
    
    ProcessAnalyzer analyzer(proc);
    
    timespec requested = {};
    requested.tv_sec  = 20;
    requested.tv_nsec = 0;
    
    timespec remaining = {};
    
    nanosleep(&requested, &remaining);
    
    analyzer.checkAndDisplay(reader.getInfo());
    
    return 0;
#endif


#if 1
    ProcessReader reader;

    // Initialize the process list to compare to.
    ProcessAnalyzer analyzer(reader.getInfo());
    
    timespec requested = {};
    requested.tv_nsec = 500000000;    // 500 ms
    
    timespec remaining = {};

    // Check process list for changes and display them.
    while (1)
    {
        analyzer.checkAndDisplay(reader.getInfo());

        if (-1 == nanosleep(&requested, &remaining))
        {
            if (EINTR == errno)
            {
                std::cout << "Interrupted by a signal" << std::endl;
                return 0;
            }
            else
            {
                perror("nanosleep");
                return 1;
            }
        }
    }
    
    return 0;
#endif
}
