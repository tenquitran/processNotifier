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
    
    // TODO: test
    Processes p = reader.getInfo();
    std::cout << "Process count: " << p.size() << std::endl;
    return 0;

    // Initialize the process list that will be analyzed.
    ProcessAnalyzer analyzer(reader.getInfo());
    
    timespec requested = {};
    requested.tv_nsec = 100000000;    // 100 ms
    
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
