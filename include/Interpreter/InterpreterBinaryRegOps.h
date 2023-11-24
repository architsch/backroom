#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"

void InterpreterBinaryRegOp(ProgramState* state, int (*op)(ProgramState* state, int regValue1, int regValue2))
{
    int regIndex1 = InterpreterRegIndexQuery(state);
    int regIndex2 = InterpreterRegIndexQuery(state);
    state->reg[regIndex1] = op(state, state->reg[regIndex1], state->reg[regIndex2]);
}

void Interpreter_Copy(ProgramState* state)
{
    InterpreterBinaryRegOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue2;
    });
}
void Interpreter_Add(ProgramState* state)
{
    InterpreterBinaryRegOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 + regValue2;
    });
}
void Interpreter_Sub(ProgramState* state)
{
    InterpreterBinaryRegOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 - regValue2;
    });
}
void Interpreter_Mul(ProgramState* state)
{
    InterpreterBinaryRegOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 * regValue2;
    });
}
void Interpreter_Div(ProgramState* state)
{
    InterpreterBinaryRegOp(state, [](ProgramState* state, int regValue1, int regValue2) {
        return regValue1 / regValue2;
    });
}