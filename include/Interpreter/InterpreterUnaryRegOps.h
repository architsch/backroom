#pragma once

#include "Interpreters.h"
#include "InterpreterRegIndexQuery.h"

void InterpreterUnaryRegOp(ProgramState* state, int (*op)(ProgramState* state, int regValue))
{
    int regIndex = InterpreterRegIndexQuery(state);
    state->reg[regIndex] = op(state, state->reg[regIndex]);
}

void Interpreter_Peek(ProgramState* state)
{
    InterpreterUnaryRegOp(state, [](ProgramState* state, int regValue) { return state->stack.top(); });
}
void Interpreter_Pop(ProgramState* state)
{
    InterpreterUnaryRegOp(state, [](ProgramState* state, int regValue) {
        int v = state->stack.top();
        state->stack.pop();
        return v;
    });
}
void Interpreter_Push(ProgramState* state)
{
    InterpreterUnaryRegOp(state, [](ProgramState* state, int regValue) {
        state->stack.push(regValue);
        return regValue;
    });
}
void Interpreter_PrintReg(ProgramState* state)
{
    InterpreterUnaryRegOp(state, [](ProgramState* state, int regValue) {
        cout << to_string(regValue);
        return regValue;
    });
}