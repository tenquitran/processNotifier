#include <cassert>
#include "ProcessAnalyzer.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////


ProcessAnalyzer::ProcessAnalyzer(const Processes& procInfo)
    : m_current(procInfo)
{
}

void ProcessAnalyzer::checkAndDisplay(const Processes& procInfo)
{
    // TODO: implement
    assert(false);
    
    // TODO: the last statement
    m_current = procInfo;
}
