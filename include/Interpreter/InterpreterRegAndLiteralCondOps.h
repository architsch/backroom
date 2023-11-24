#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterLiteralQuery.h"
#include "InterpreterCheckpointQuery.h"

void InterpreterRegAndLiteralCondOp(ProgramState* state, bool (*op)(ProgramState* state, int regValue, int literal))
{
    int regIndex = InterpreterRegIndexQuery(state);
    int literal = InterpreterLiteralQuery(state);
    if (op(state, state->reg[regIndex], literal))
        state->goto_pending_instIndex = InterpreterCheckpointQuery(state);
}

void Interpreter_Equalv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue == literal;
    });
}
void Interpreter_NotEqualv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue != literal;
    });
}
void Interpreter_GreaterThanv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue > literal;
    });
}
void Interpreter_GreaterThanOrEqualv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue >= literal;
    });
}
void Interpreter_LessThanv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue < literal;
    });
}
void Interpreter_LessThanOrEqualv(ProgramState* state)
{
    InterpreterRegAndLiteralCondOp(state, [](ProgramState* state, int regValue, int literal) {
        return regValue <= literal;
    });
}