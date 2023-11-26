#include "ProgramStateDebug.h"

void ProgramStateDebug::debugRegState(ProgramState* state, int minRegIndex, int maxRegIndex)
{
    if (!LogUtil::isLogTypeEnabled(LogUtil::LogType::REG_STATE))
        return;
    
    string valueDebugStr = "\nRegister State ::\n[";
    string indexDebugStr = "[";
    int i1 = max(0, minRegIndex);
    int i2 = min(state->regSize - 1, maxRegIndex);
    for (int i = i1; i <= i2; ++i)
    {
        valueDebugStr += to_string(state->reg[i]) + "\t";
        indexDebugStr += to_string(i) + "\t";
    }
    valueDebugStr += "]\n";
    indexDebugStr += "]\n";
    string debugStr = valueDebugStr + indexDebugStr;
    LogUtil::log(debugStr, {}, LogUtil::LogType::REG_STATE);
}