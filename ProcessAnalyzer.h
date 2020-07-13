#ifndef PROCESS_ANALYZER_H
#define PROCESS_ANALYZER_H

#include "ProcessInfo.h"


namespace ProcessNotifierApp
{
    class ProcessAnalyzer
    {
    public:
        // Parameters: procInfo - process collection;
        //             processToWait - name of the process for whose enter and exit we'll wait.
        explicit ProcessAnalyzer(const Processes& procInfo, const std::string& processToWait = "");
    
        // Check for differences in the process collection and display these differences, if any.
        // Parameters: newInfo - new process collection.
        void checkAndDisplay(const Processes& newInfo);
    
    private:
        // Current process collection.
        ProcessNotifierApp::Processes m_current;
        
        // Optional name of the process for whose enter and exit we'll wait.
        // If empty, we are working with all processes.
        std::string m_processToWait;
    };
}

#endif
