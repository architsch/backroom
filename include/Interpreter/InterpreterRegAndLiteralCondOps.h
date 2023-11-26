#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"
#include "InterpreterLiteralQuery.h"
#include "InterpreterCheckpointQuery.h"

void InterpreterRegAndLiteralCondOp(ProgramState* state, InterpreterMode::Enum mode, bool (*op)(ProgramState* state, int regValue, int literal))
{
    if (mode == InterpreterMode::Run)
    {
        int regIndex = InterpreterRegIndexQuery(state);
        int literal = InterpreterLiteralQuery(state);
        if (op(state, state->reg[regIndex], literal))
        {
            state->goto_pending_instIndex = InterpreterCheckpointQuery(state);
        }
    }
}

void Interpreter_Equalv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue == literal;
    });
}
void Interpreter_NotEqualv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue != literal;
    });
}
void Interpreter_GreaterThanv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue > literal;
    });
}
void Interpreter_GreaterThanOrEqualv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue >= literal;
    });
}
void Interpreter_LessThanv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue < literal;
    });
}
void Interpreter_LessThanOrEqualv(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterRegAndLiteralCondOp(state, mode, [](ProgramState* state, int regValue, int literal) {
        return regValue <= literal;
    });
}