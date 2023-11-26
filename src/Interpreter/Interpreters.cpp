#include "Interpreters.h"
#include "Interpreter_Checkpoint.h"
#include "Interpreter_Goto.h"
#include "Interpreter_PrintText.h"
#include "InterpreterBinaryRegOps.h"
#include "InterpreterBinaryRegCondOps.h"
#include "InterpreterUnaryRegOps.h"
#include "InterpreterRegAndLiteralOps.h"
#include "InterpreterRegAndLiteralCondOps.h"

vector<string> interpreterNames {
    // Standalone
    ":",
    "goto",
    "print-text",

    // InterpreterBinaryRegOps
    "=",
    "+",
    "-",
    "*",
    "/",

    // InterpreterRegAndLiteralOps
    "='",
    "+'",
    "-'",
    "*'",
    "/'",

    // InterpreterBinaryRegCondOp
    "==",
    "!=",
    ">",
    ">=",
    "<",
    "<=",

    // InterpreterRegAndLiteralCondOp
    "=='",
    "!='",
    ">'",
    ">='",
    "<'",
    "<='",

    // InterpreterUnaryRegOps
    "peek",
    "pop",
    "push",
    "print-reg",
};

vector<interpreter_func_t> interpreters {
    // Standalone
    Interpreter_Checkpoint,
    Interpreter_Goto,
    Interpreter_PrintText,

    // InterpreterBinaryRegOps
    Interpreter_Copy,
    Interpreter_Add,
    Interpreter_Sub,
    Interpreter_Mul,
    Interpreter_Div,

    // InterpreterRegAndLiteralOps
    Interpreter_Copyv,
    Interpreter_Addv,
    Interpreter_Subv,
    Interpreter_Mulv,
    Interpreter_Divv,

    // InterpreterBinaryRegCondOp
    Interpreter_Equal,
    Interpreter_NotEqual,
    Interpreter_GreaterThan,
    Interpreter_GreaterThanOrEqual,
    Interpreter_LessThan,
    Interpreter_LessThanOrEqual,

    // InterpreterRegAndLiteralCondOp
    Interpreter_Equalv,
    Interpreter_NotEqualv,
    Interpreter_GreaterThanv,
    Interpreter_GreaterThanOrEqualv,
    Interpreter_LessThanv,
    Interpreter_LessThanOrEqualv,

    // InterpreterUnaryRegOps
    Interpreter_Peek,
    Interpreter_Pop,
    Interpreter_Push,
    Interpreter_PrintReg,
};