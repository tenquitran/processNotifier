#include <cassert>
#include <iostream>    // TODO: temp
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include "ProcessReader.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////


Processes ProcessReader::getInfo() const
{
    Processes processes;
    
    DIR *proc = opendir("/proc");
	if (!proc)
	{
		perror("opendir(/proc)");
		return processes;
	}

    dirent *entry = nullptr;
    
    while (entry = readdir(proc))
    {
        if (!isdigit(*entry->d_name))
        {
            // Skip the entries like "cpuinfo", etc.
            continue;
        }
        
        long pid = strtol(entry->d_name, nullptr, 10);
		if (0 == pid)
		{
            perror(entry->d_name);
            continue;
		}

        // TODO: temp
        std::cout << "PID: " << pid << std::endl;
        
        // TODO: add other data
        ProcessInfo proc;
        proc.m_pid = pid;
        
        processes.emplace(pid, proc);
    }
    
    // TODO: implement
    //assert(false);
    
    if (-1 == closedir(proc))
	{
		perror("closedir(/proc)");
	}
    
    return processes;
}
