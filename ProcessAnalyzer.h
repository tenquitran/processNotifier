#ifndef PROCESS_ANALYZER_H
#define PROCESS_ANALYZER_H

#include "ProcessInfo.h"


namespace ProcessNotifierApp
{
    class ProcessAnalyzer
    {
    public:
        explicit ProcessAnalyzer(const Processes& procInfo);
    
        // Check for differences in the process collection and display these differences, if any.
        // Parameters: newInfo - new process collection.
        void checkAndDisplay(const Processes& newInfo);
    
    private:
        // Current process collection.
        ProcessNotifierApp::Processes m_current;
    };
}

#endif
