#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"

void InterpreterUnaryRegOp(ProgramState* state, InterpreterMode::Enum mode, int (*op)(ProgramState* state, int regValue))
{
    if (mode == InterpreterMode::Run)
    {
        int regIndex = InterpreterRegIndexQuery(state);
        state->reg[regIndex] = op(state, state->reg[regIndex]);
    }
}

void Interpreter_Peek(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterUnaryRegOp(state, mode, [](ProgramState* state, int regValue) {
        return state->stack.top();
    });
}
void Interpreter_Pop(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterUnaryRegOp(state, mode, [](ProgramState* state, int regValue) {
        int v = state->stack.top();
        state->stack.pop();
        ProgramStateDebug::debugRegState(state, 0, 9);
        return v;
    });
}
void Interpreter_Push(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterUnaryRegOp(state, mode, [](ProgramState* state, int regValue) {
        state->stack.push(regValue);
        return regValue;
    });
}
void Interpreter_PrintReg(ProgramState* state, InterpreterMode::Enum mode)
{
    InterpreterUnaryRegOp(state, mode, [](ProgramState* state, int regValue) {
        cout << to_string(regValue);
        return regValue;
    });
}