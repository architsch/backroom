#include "ByteCode.h"

int runByteCode(string byteCodeFilePath)
{
    ProgramState state;

    //------------------------------------------------------------------------------
    // Reset the register values.
    //------------------------------------------------------------------------------

    for (int i = 0; i < state.regSize; ++i)
    {
        state.reg[i] = 0;
    }

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
    int numInst = instList.size();
    
    //------------------------------------------------------------------------------
    // Interpret the byte code.
    //------------------------------------------------------------------------------

    int numInterpreterModes = 2;

    InterpreterMode::Enum interpreterModes[] = {
        InterpreterMode::Preprocess,
        InterpreterMode::Run,
    };
    string interpreterModeLogTitles[] = {
        "Preprocessing...",
        "Running...",
    };
    LogUtil::LogType interpreterModeLogTypes[] = {
        LogUtil::LogType::BYTE_CODE_PREPROCESS,
        LogUtil::LogType::BYTE_CODE_RUN,
    };

    for (int mode = 0; mode < numInterpreterModes; ++mode)
    {
        state.instIndex = 0;
        state.goto_pending_instIndex = 0;

        while (state.instIndex < numInst)
        {
            string inst = instList[state.instIndex];
            char instType = inst[0] - INST_TYPE_ASCII_OFFSET;
            state.paramStr = inst.substr(1);
            state.paramStrParseIndex = 0;
            LogUtil::log(interpreterModeLogTitles[mode], {{"instType", interpreterNames[instType]}, {"paramStr", state.paramStr}, {"instIndex", to_string(state.instIndex)}}, interpreterModeLogTypes[mode]);
            interpreters[instType](&state, interpreterModes[mode]);

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
    }
    
    return 0;
}