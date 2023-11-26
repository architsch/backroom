#pragma once

#include "Interpreters.h"
#include "InterpreterCheckpointQuery.h"

void Interpreter_Goto(ProgramState* state, InterpreterMode::Enum mode)
{
    if (mode == InterpreterMode::Run)
    {
        state->goto_pending_instIndex = InterpreterCheckpointQuery(state);
    }
}