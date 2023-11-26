#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterLiteralQuery.h"

void InterpreterRegAndLiteralOp(ProgramState* state, InterpreterMode::Enum mode, int (*op)(ProgramState* state, int regValue, int literal))
{
    if (mode == InterpreterMode::Run)
    {
        int regIndex = InterpreterRegIndexQuery(state);
        int literal = InterpreterLiteralQuery(state);
        state->reg[regIndex] = op(state, state->reg[regIndex], literal);
        ProgramStateDebug::debugRegState(state, 0, 9);
    }
}

void Interpreter_Copyv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return literal;
    });
}
void Interpreter_Addv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue + literal;
    });
}
void Interpreter_Subv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue - literal;
    });
}
void Interpreter_Mulv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue * literal;
    });
}
void Interpreter_Divv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue / literal;
    });
}