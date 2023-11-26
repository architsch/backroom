#pragma once

#include <vector>
#include <set>
#include <stack>
#include <string>

using namespace std;

struct ProgramState {
    int instIndex = 0;
    int goto_pending_instIndex = 0;
    int reg[1024];
    int regSize = 1024;
    stack<int> stack;
    unordered_map<string, int> checkpointByName;
    string paramStr;
    int paramStrParseIndex;
};