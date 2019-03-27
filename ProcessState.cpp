#include <cassert>
#include "ProcessState.h"

////////////////////////////////////////////////////////////

using namespace ProcessNotifierApp;

////////////////////////////////////////////////////////////


EProcessState ProcessStateConverter::charToState(char c)
{
    switch (c)
    {
    case 'R':
        return EProcessState::Running;
    case 'S':
        return EProcessState::Sleeping;
    case 'D':
        return EProcessState::DiskSleep;
    case 'Z':
        return EProcessState::Zombie;
    case 'T':
        return EProcessState::StoppedOnSignal;
    case 't':
        return EProcessState::TracingStop;
    case 'X':
    case 'x':
        return EProcessState::Dead;
    case 'K':
        return EProcessState::Wakekill;
    case 'W':
        return EProcessState::Waking;
        /* return EProcessState::Paging;    // before Linux 2.6.0, can be considered obsolete */
    case 'P':
        return EProcessState::Parked;
    case ' ':
        return EProcessState::Unknown;
    default:
        return EProcessState::Undefined;
    }
}

std::string ProcessStateConverter::stateToString(EProcessState state)
{
    switch (state)
    {
    case EProcessState::Running:
        return "running";
    case EProcessState::Sleeping:
        return "sleeping";
    case EProcessState::DiskSleep:
        return "diskSleep";
    case EProcessState::Zombie:
        return "zombie";
    case EProcessState::StoppedOnSignal:
        return "stoppedOnSignal";
    case EProcessState::TracingStop:
        return "tracingStop";
    case EProcessState::Paging:
        return "paging";
    case EProcessState::Dead:
        return "dead";
    case EProcessState::Wakekill:
        return "wakekill";
    case EProcessState::Waking:
        return "waking";
    case EProcessState::Parked:
        return "parked";
    case EProcessState::Unknown:
        return "unknown";
    default:
        //assert(false);
        return "undefined";
    }
}
