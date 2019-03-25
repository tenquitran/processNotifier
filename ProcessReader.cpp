#include <cassert>
#include <iostream>    // TODO: temp
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "ProcessReader.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////

// Size of the buffer to hold path to executable.
const int MAX_PATH = 256;

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
    
    char path[MAX_PATH];
    char buff[MAX_PATH];
    
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
        
        ProcessInfo proc;
        proc.m_pid = pid;
        
        // Read path to the process executable.
        
        bzero(path, MAX_PATH);
        bzero(buff, MAX_PATH);

        sprintf(path, "/proc/%d/exe", pid);
        
        if (-1 == readlink(path, buff, MAX_PATH))
        {
            perror("readlink");
        }
        else
        {
            proc.m_path.assign(buff);
        }
        
        // TODO: read other data
        
        bzero(path, MAX_PATH);
        
        sprintf(path, "/proc/%d/stat", pid);
        
        //std::cout << "Path (2):\n" << path << std::endl;
        
        FILE* procStat = fopen(path, "r");
#if 1
        if (!procStat)
        {
            perror("fopen(/proc/<PID>/stat)");
        }
        else
        {
            //std::cout << "OK(2)" << std::endl;
            
            readProcessStatus(procStat, proc);
            
            if (0 != fclose(procStat))
                {perror("fclose");}
        }
#endif

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

void ProcessReader::readProcessStatus(FILE* fd, ProcessInfo& procInfo) const
{
    // Process ID.
    
    pid_t pid = {};
    fscanf(fd, "%d", &pid);
    
    if (pid != procInfo.m_pid)
    {
        std::cerr << "Invalid PID: expected " << procInfo.m_pid << ", actual " << pid << '\n';
        return;
    }
    
    // Executable name.

    char buff[MAX_PATH];
    
    fscanf(fd, "%s", buff);
    
    procInfo.m_exeName.assign(buff);
    
    if ('(' == procInfo.m_exeName[0])
    {
        // Remove the enclosing parentheses.
        procInfo.m_exeName.erase(0, 1);
        procInfo.m_exeName.erase(procInfo.m_exeName.length() - 1, 1);
    }
    
    
    // TODO: other data
}
