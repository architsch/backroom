#include "SourceCode.h"
#include "Interpreters.h"

int parseSourceCode(string sourceCodeFilePath, string byteCodeFilePath)
{
    unordered_map<string, char> instTypeCharByKeyword;
    int N = interpreters.size();
    if (N != interpreterNames.size())
    {
        LogUtil::error("Interpreter array size mismatch.", {});
        return 1;
    }
    for (int i = 0; i < N; ++i)
    {
        LogUtil::log("Registering instTypeChar...", {{"interpreterName", interpreterNames[i]}, {"instTypeChar", to_string(i + INST_TYPE_ASCII_OFFSET)}}, LogUtil::LogType::INST_TYPE_CHAR_INIT);
        instTypeCharByKeyword.insert({interpreterNames[i], i + INST_TYPE_ASCII_OFFSET});
    }

    //------------------------------------------------------------------------------
    // Initialize the file streams.
    //------------------------------------------------------------------------------

    ifstream fileIn(sourceCodeFilePath);
    if (!fileIn.is_open())
    {
        LogUtil::error("Couldn't open the sourceCode file.", {});
        return 1;
    }

    ofstream fileOut(byteCodeFilePath, ofstream::trunc);
    if (!fileOut.is_open())
    {
        LogUtil::error("Couldn't open the byteCode file.", {});
        return 1;
    }

    //------------------------------------------------------------------------------
    // Parse source code to byte code.
    //------------------------------------------------------------------------------

    string sourceLine;
    while (getline(fileIn, sourceLine))
    {
        int startIndex = 0;
        string instTypeKeyword = StringUtil::readWord(sourceLine, startIndex);
        if (instTypeKeyword.size() == 0)
        {
            continue;
        }
        
        if (instTypeKeyword.size() == 0) // Ignore any blank line.
            continue;

        if (instTypeCharByKeyword.find(instTypeKeyword) == instTypeCharByKeyword.end()) // Check if the type exists.
        {
            LogUtil::error("Unknown instruction type keyword", {{"instTypeKeyword", instTypeKeyword}});
            continue;
        }

        fileOut.put(instTypeCharByKeyword[instTypeKeyword]);

        string valueStr = StringUtil::trim(sourceLine.substr(startIndex));
        int N = valueStr.size();
        int i = 0;
        while (i < N)
            fileOut.put(valueStr[i++]);
        fileOut.put('\n');
    }
    fileIn.close();
    fileOut.close();
    return 0;
}