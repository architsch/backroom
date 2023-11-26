#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"

void InterpreterBinaryRegOp(ProgramState* state, InterpreterMode::Enum mode, int (*op)(ProgramState* state, int regValue1, int regValue2))
{
    if (mode == InterpreterMode::Run)
    {
        int regIndex1 = InterpreterRegIndexQuery(state);
        int regIndex2 = InterpreterRegIndexQuery(state);
        state->reg[regIndex1] = op(state, state->reg[regIndex1], state->reg[regIndex2]);
        ProgramStateDebug::debugRegState(state, 0, 9);
    }
}

void Interpreter_Copy(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue2;
    });
}
void Interpreter_Add(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 + regValue2;
    });
}
void Interpreter_Sub(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 - regValue2;
    });
}
void Interpreter_Mul(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 * regValue2;
    });
}
void Interpreter_Div(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterBinaryRegOp(state, mode, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 / regValue2;
    });
}