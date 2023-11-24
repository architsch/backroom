#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "CodeConstants.h"
#include "StringUtil.h"
#include "LogUtil.h"
#include "ProgramState.h"

#include "Interpreters.h"

using namespace std;

int runByteCode(string byteCodeFilePath);