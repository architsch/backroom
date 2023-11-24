#pragma once

#include "Interpreters.h"

int InterpreterLiteralQuery(ProgramState* state)
{
    string literalStr = StringUtil::readWord(state->paramStr, state->paramStrParseIndex);
    if (literalStr.size() == 0)
    {
        LogUtil::error("literalStr not specified.", {});
        return 0;
    }
    return stoi(literalStr);
}