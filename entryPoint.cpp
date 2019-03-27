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
    ProcessReader reader;

    // Initialize the process list to compare to.
    ProcessAnalyzer analyzer(reader.getInfo());
    
    timespec requested = {};
    requested.tv_nsec = 200000000;    // 200 ms
    
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
}
