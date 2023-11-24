#pragma once

#include <set>
#include <string>
#include "LogUtil.h"

using namespace std;

namespace StringUtil
{
    bool isTrimmableChar(char c);
    string trim(string str);
    string removeStartAndEndChars(string str);
    string parseEscapeChars(string str);
    string readWord(string str, int& startIndex);
    string readLine(string str, int& startIndex);
}