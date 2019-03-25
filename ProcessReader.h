#ifndef PROCESS_READER_H
#define PROCESS_READER_H

#include "ProcessInfo.h"


namespace ProcessNotifierApp
{
    class ProcessReader
    {
    public:
        // Get information on current processes.
        Processes getInfo() const;

    private:
        // Read status information about the process.
        // Parameters: fd - pointer to the file containing status information;
        //             procInfo - data structure to store status information.
        void readProcessStatus(FILE* fd, ProcessInfo& procInfo) const;
    };
}

#endif
