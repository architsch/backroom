#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "CodeConstants.h"
#include "ProgramState.h"
#include "StringUtil.h"
#include "LogUtil.h"

using namespace std;

extern vector<string> interpreterNames;

typedef void (*interpreter_func_t)(ProgramState* state);
extern vector<interpreter_func_t> interpreters;