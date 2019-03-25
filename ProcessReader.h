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
    };
}

#endif
