#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterCheckpointQuery.h"

void InterpreterBinaryRegCondOp(ProgramState* state, bool (*op)(ProgramState* state, int regValue1, int regValue2))
{
    int regIndex1 = InterpreterRegIndexQuery(state);
    int regIndex2 = InterpreterRegIndexQuery(state);
    if (op(state, state->reg[regIndex1], state->reg[regIndex2]))
        state->goto_pending_instIndex = InterpreterCheckpointQuery(state);
}

void Interpreter_Equal(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 == regValue2;
    });
}
void Interpreter_NotEqual(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 != regValue2;
    });
}
void Interpreter_GreaterThan(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 > regValue2;
    });
}
void Interpreter_GreaterThanOrEqual(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 >= regValue2;
    });
}
void Interpreter_LessThan(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 < regValue2;
    });
}
void Interpreter_LessThanOrEqual(ProgramState* state)
{
    InterpreterBinaryRegCondOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 <= regValue2;
    });
}