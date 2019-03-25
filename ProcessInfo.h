#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include <unistd.h>
#include <string>
#include <map>


namespace ProcessNotifierApp
{
    struct ProcessInfo
    {
        pid_t m_pid = {};
        std::string m_path;
        std::string m_exeName;
        // ...
    };


    // Data about processes.
    // Key: process ID.
    typedef std::map<pid_t, ProcessInfo> Processes;
}

#endif
