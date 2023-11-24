#pragma once

#include "Interpreters.h"

void Interpreter_Checkpoint(ProgramState* state)
{
    string name = StringUtil::readWord(state->paramStr, state->paramStrParseIndex);
    if (name.size() == 0)
    {
        LogUtil::error("No checkpoint name specified.", {});
        return;
    }
    if (state->checkpointByName.find(name) != state->checkpointByName.end()) // Checkpoint is already registered, so let's just move on.
    {
        return;
    }
    state->checkpointByName.insert({name, state->instIndex + 1});
}