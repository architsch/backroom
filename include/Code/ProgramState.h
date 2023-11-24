#pragma once

#include <vector>
#include <set>
#include <stack>

using namespace std;

#define PROGRAM_STATE_REG_SIZE 1024

struct ProgramState {
    int instIndex = 0;
    int goto_pending_instIndex = 0;
    int reg[PROGRAM_STATE_REG_SIZE];
    stack<int> stack;
    unordered_map<string, int> checkpointByName;
    string paramStr;
    int paramStrParseIndex;
};