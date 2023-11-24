#pragma once

#include "Interpreters.h"

streampos InterpreterCheckpointQuery(ProgramState* state)
{
    string name = StringUtil::readWord(state->paramStr, state->paramStrParseIndex);
    if (name.size() == 0)
    {
        LogUtil::error("No checkpoint name specified.", {});
        return 0;
    }
    if (state->checkpointByName.find(name) == state->checkpointByName.end())
    {
        LogUtil::error("Checkpoint not found.", {{"name", name}});
        return 0;
    }
    return state->checkpointByName[name];
}