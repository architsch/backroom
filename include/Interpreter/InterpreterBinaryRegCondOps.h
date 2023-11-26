#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterCheckpointQuery.h"

void InterpreterBinaryRegCondOp(ProgramState* state, InterpreterMode::Enum mode, bool (*op)(ProgramState* state, int regValue1, int regValue2))
{
    if (mode == InterpreterMode::Run)
    {
        int regIndex1 = InterpreterRegIndexQuery(state);
        int regIndex2 = InterpreterRegIndexQuery(state);
        if (op(state, state->reg[regIndex1], state->reg[regIndex2]))
        {
            state->goto_pending_instIndex = InterpreterCheckpointQuery(state);
        }
    }
}

void Interpreter_Equal(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 == regValue2;
    });
}
void Interpreter_NotEqual(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 != regValue2;
    });
}
void Interpreter_GreaterThan(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 > regValue2;
    });
}
void Interpreter_GreaterThanOrEqual(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 >= regValue2;
    });
}
void Interpreter_LessThan(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 < regValue2;
    });
}
void Interpreter_LessThanOrEqual(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegCondOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 <= regValue2;
    });
}