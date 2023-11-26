#pragma once

#include "ProgramState.h"
#include "LogUtil.h"

namespace ProgramStateDebug
{
    void debugRegState(ProgramState* state, int minRegIndex, int maxRegIndex);
}