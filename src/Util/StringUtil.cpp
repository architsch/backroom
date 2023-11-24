#include "StringUtil.h"

set<char> trimmableChars = { ' ', '\t' };

bool StringUtil::isTrimmableChar(char c)
{
    return trimmableChars.find(c) != trimmableChars.end();
}

string StringUtil::trim(string str)
{
    int N = str.size();
    int startIndex = 0;
    int endIndex = N-1;

    while (startIndex < N && isTrimmableChar(str[startIndex]))
        ++startIndex;
    while (endIndex > startIndex && isTrimmableChar(str[endIndex]))
        --endIndex;
    return str.substr(startIndex, endIndex - startIndex + 1);
}

string StringUtil::removeStartAndEndChars(string str)
{
    int N = str.size();
    return str.substr(1, N-2);
}

string StringUtil::parseEscapeChars(string str)
{
    int N = str.size();
    string str2;
    str2.reserve(N);
    str2.resize(N);

    int i1 = -1;
    int i2 = 0;
    while (++i1 < N)
    {
        char charToAdd = str[i1];
        if (charToAdd == '\\')
        {
            char escapeType = str[++i1];
            switch (escapeType)
            {
                case 'n': charToAdd = '\n'; break;
                case 't': charToAdd = '\t'; break;
                case 'r': charToAdd = '\r'; break;
                case '\\': charToAdd = '\\'; break;
                default: charToAdd = '?'; break;
            }
        }
        str2[i2++] = charToAdd;
    }
    str2.resize(i2);
    return str2;
}

string StringUtil::readWord(string str, int& startIndex)
{
    int N = str.size();
    LogUtil::log("StringUtil::readWord -> Initial Status", {{"str", str}, {"N", to_string(N)}, {"startIndex", to_string(startIndex)}}, LogUtil::LogType::STRING_PARSE);
    while (startIndex < N && isTrimmableChar(str[startIndex]))
    {
        LogUtil::log("StringUtil::readWord -> Front Trimming", {{"str", str}, {"N", to_string(N)}, {"startIndex", to_string(startIndex)}}, LogUtil::LogType::STRING_PARSE);
        ++startIndex;
    }

    int endIndex = startIndex;
    LogUtil::log("StringUtil::readWord -> Before Char Detection", {{"str", str}, {"N", to_string(N)}, {"startIndex", to_string(startIndex)}, {"endIndex", to_string(endIndex)}}, LogUtil::LogType::STRING_PARSE);
    while (endIndex < N && !isTrimmableChar(str[endIndex]))
    {
        LogUtil::log("StringUtil::readWord -> Char Detection", {{"str", str}, {"N", to_string(N)}, {"endIndex", to_string(endIndex)}}, LogUtil::LogType::STRING_PARSE);
        ++endIndex;
    }

    if (endIndex == startIndex)
        return "";

    string word = str.substr(startIndex, endIndex - startIndex);
    startIndex = endIndex + 1;
    return word;
}

string StringUtil::readLine(string str, int& startIndex)
{
    int N = str.size();

    while (startIndex < N && isTrimmableChar(str[startIndex]))
        ++startIndex;
    
    string rest = str.substr(startIndex);
    startIndex = N;
    return rest;
}