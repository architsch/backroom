#pragma once

#include "Interpreters.h"

void Interpreter_Checkpoint(ProgramState* state, InterpreterMode::Enum mode)
{
    if (mode == InterpreterMode::Preprocess)
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
        int targetInstIndex = state->instIndex + 1;
        state->checkpointByName.insert({name, targetInstIndex});
        LogUtil::log("Added checkpoint", {{"name", name}, {"instIndex", to_string(targetInstIndex)}}, LogUtil::LogType::CHECKPOINT_ADD);
    }
}