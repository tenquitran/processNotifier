#ifndef PROCESS_ANALYZER_H
#define PROCESS_ANALYZER_H

#include "ProcessInfo.h"


namespace ProcessNotifierApp
{
    class ProcessAnalyzer
    {
    public:
        explicit ProcessAnalyzer(const Processes& procInfo);
    
        void checkAndDisplay(const Processes& procInfo);
    
    private:
        // Current process list.
        ProcessNotifierApp::Processes m_current;
    };
}

#endif
