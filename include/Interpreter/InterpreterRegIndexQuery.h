#pragma once

#include "Interpreters.h"

int InterpreterRegIndexQuery(ProgramState* state)
{
    string regIndexStr = StringUtil::readWord(state->paramStr, state->paramStrParseIndex);
    if (regIndexStr.size() == 0)
    {
        LogUtil::error("regIndexStr not specified.", {});
        return 0;
    }
    int regIndex = stoi(regIndexStr);
    if (regIndex < 0 || regIndex >= state->regSize)
    {
        LogUtil::error("regIndex is out of bound.", {{"regIndex", to_string(regIndex)}});
        return 0;
    }
    return regIndex;
}