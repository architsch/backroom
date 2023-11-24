#pragma once

#include "Interpreters.h"

void Interpreter_PrintText(ProgramState* state)
{
    string line =
        StringUtil::parseEscapeChars(
            StringUtil::removeStartAndEndChars(
                StringUtil::readLine(state->paramStr, state->paramStrParseIndex))); // Read the line and remove the double quotes.

    if (line.size() == 0)
    {
        LogUtil::error("Text is empty.", {});
        return;
    }
    cout << line;
}