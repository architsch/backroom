#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace LogUtil
{
    struct LogParam
    {
        string key;
        string value;
    };

    enum LogType
    {
        ERROR,
        CORE,
        INST_TYPE_CHAR_INIT,
        BYTE_CODE_PREPROCESS,
        BYTE_CODE_RUN,
        REG_STATE,
        CHECKPOINT_ADD,
        STRING_PARSE,
    };

    bool isLogTypeEnabled(LogType logType);
    void setLogTypeEnabled(LogType logType, bool enabled);
    void log(string str, vector<LogParam> logParams, LogType logType);
    void error(string str, vector<LogParam> logParams);
}