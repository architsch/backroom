#include "ByteCode.h"

int runByteCode(string byteCodeFilePath)
{
    ProgramState state;

    //------------------------------------------------------------------------------
    // Initialize the file stream.
    //------------------------------------------------------------------------------

    ifstream fileIn(byteCodeFilePath);
    if (!fileIn.is_open())
    {
        LogUtil::error("Couldn't open the byteCode file.", {});
        return 1;
    }

    //------------------------------------------------------------------------------
    // Read the byte code.
    //------------------------------------------------------------------------------

    vector<string> instList;
    string inst;
    while (getline(fileIn, inst))
    {
        inst = StringUtil::trim(inst);
        if (inst.size() > 0)
            instList.push_back(inst);
    }
    
    //------------------------------------------------------------------------------
    // Run the byte code.
    //------------------------------------------------------------------------------

    int numInst = instList.size();
    while (state.instIndex < numInst)
    {
        string inst = instList[state.instIndex];
        char instType = inst[0] - INST_TYPE_ASCII_OFFSET;
        state.paramStr = inst.substr(1);
        state.paramStrParseIndex = 0;
        LogUtil::log("Interpreting...", {{"instType", interpreterNames[instType]}, {"paramStr", state.paramStr}}, LogUtil::LogType::BYTE_CODE_PARSE);
        interpreters[instType](&state);

        if (state.goto_pending_instIndex != 0)
        {
            state.instIndex = state.goto_pending_instIndex;
            state.goto_pending_instIndex = 0;
        }
        else
        {
            ++state.instIndex;
        }
    }
    
    return 0;
}