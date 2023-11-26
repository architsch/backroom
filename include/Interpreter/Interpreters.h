#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "CodeConstants.h"
#include "ProgramState.h"
#include "ProgramStateDebug.h"
#include "StringUtil.h"
#include "LogUtil.h"

using namespace std;

namespace InterpreterMode
{
    enum Enum
    {
        Preprocess,
        Run,
    };
}

extern vector<string> interpreterNames;

typedef void (*interpreter_func_t)(ProgramState* state, InterpreterMode::Enum mode);
extern vector<interpreter_func_t> interpreters;