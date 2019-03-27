#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "ProcessAnalyzer.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////


ProcessAnalyzer::ProcessAnalyzer(const Processes& procInfo)
    : m_current(procInfo)
{
    if (m_current.empty())
    {
        assert(false); throw std::runtime_error("Empty process collection");
    }
}

void ProcessAnalyzer::checkAndDisplay(const Processes& newInfo)
{
    if (newInfo == m_current)
    {   // No changes in the process list.
        return;
    }
    
    // Step 1. Find the processes that no longer exist.
    
    size_t maxDiffSize = std::max(m_current.size(), newInfo.size());
    
    std::vector<ProcessInfo> terminated(maxDiffSize);

    std::vector<ProcessInfo>::iterator itd = 
        std::set_difference(m_current.begin(), m_current.end(), newInfo.begin(), newInfo.end(), terminated.begin());

    // Remove excessive elements with default values.
    terminated.resize(itd - terminated.begin());
    
    // Display the terminated processes info.
    
    if (!terminated.empty())
    {
        std::cout << "Terminated processes:\n---------------------\n";
    }
    
    for (const auto& itr : terminated)
    {
        itr.display();
    }
    
    // Step 2. Find new processes.
    
    std::vector<ProcessInfo> created(maxDiffSize);
    
    itd = std::set_difference(newInfo.begin(), newInfo.end(), m_current.begin(), m_current.end(), created.begin());
    
    created.resize(itd - created.begin());
    
    if (!created.empty())
    {
        std::cout << "Created processes:\n------------------\n";
    }
    
    // Display the new processes info.
    for (const auto& itr : created)
    {
        itr.display();
    }

    // Step 3. Replace the current collection of processes.
    m_current = newInfo;
}
