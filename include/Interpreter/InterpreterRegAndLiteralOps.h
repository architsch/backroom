#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterLiteralQuery.h"

void InterpreterRegAndLiteralOp(ProgramState* state, int (*op)(ProgramState* state, int regValue, int literal))
{
    int regIndex = InterpreterRegIndexQuery(state);
    int literal = InterpreterLiteralQuery(state);
    state->reg[regIndex] = op(state, state->reg[regIndex], literal);
}

void Interpreter_Copyv(ProgramState* state)
{
    InterpreterRegAndLiteralOp(state, [](ProgramState* state, int regValue, int literal) {
        return literal;
    });
}
void Interpreter_Addv(ProgramState* state)
{
    InterpreterRegAndLiteralOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue + literal;
    });
}
void Interpreter_Subv(ProgramState* state)
{
    InterpreterRegAndLiteralOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue - literal;
    });
}
void Interpreter_Mulv(ProgramState* state)
{
    InterpreterRegAndLiteralOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue * literal;
    });
}
void Interpreter_Divv(ProgramState* state)
{
    InterpreterRegAndLiteralOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue / literal;
    });
}