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
    // Optional name of the process for whose enter and exit we'll wait.
    std::string processToWait;
    
    if (1 != argc && 2 != argc)
    {
        std::cout << "Usage:\n$ procNot [process_name]" << std::endl;
        return 1;
    }
    else if (2 == argc)
    {
        processToWait = argv[1];
    }

    ProcessReader reader;

    // Initialize the process list to compare to.
    ProcessAnalyzer analyzer(reader.getInfo(), processToWait);
    
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
                return 2;
            }
        }
    }
    
    return 0;
}
