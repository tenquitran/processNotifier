#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include <unistd.h>
#include <string>
#include <set>
#include "ProcessState.h"


namespace ProcessNotifierApp
{
    struct ProcessInfo
    {
    public:
        ProcessInfo() = default;
    
        bool operator<(const ProcessInfo& other) const
        {
            if (m_path < other.m_path)
            {
                return true;
            }
            else if (m_path > other.m_path)
            {
                return false;
            }
            
            return (m_pid < other.m_pid);
        }
        
        bool operator ==(const ProcessInfo& other) const
        {
            return (   m_path == other.m_path
                    && m_pid  == other.m_pid);
        }
        
        bool operator!=(const ProcessInfo& other) const
        {
            return !(this->operator==(other));
        }
        
        // Display process information.
        void display() const
        {
            std::cout << m_pid << ": " << m_path 
                      << " (" << ProcessStateConverter::stateToString(m_state) << ")" << std::endl;
        }

    public:
        pid_t m_pid = {};
        
        std::string m_path;
        
        std::string m_exeName;
        
        EProcessState m_state = {EProcessState::Undefined};
    };


    // Process data collection.
    typedef std::set<ProcessInfo> Processes;
}

#endif
