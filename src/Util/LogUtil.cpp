#include "LogUtil.h"

unordered_map<LogUtil::LogType, bool> logEnabled = {
    {LogUtil::LogType::ERROR, true},
    {LogUtil::LogType::CORE, true},
    {LogUtil::LogType::INST_TYPE_CHAR_INIT, false},
    {LogUtil::LogType::BYTE_CODE_PREPROCESS, false},
    {LogUtil::LogType::BYTE_CODE_RUN, true},
    {LogUtil::LogType::REG_STATE, true},
    {LogUtil::LogType::CHECKPOINT_ADD, false},
    {LogUtil::LogType::STRING_PARSE, false},
};

void logProcedure(string msg, vector<LogUtil::LogParam> logParams, string outStreamLabel, ostream& outStream, LogUtil::LogType logType)
{
    if (!logEnabled[logType])
        return;

    outStream << outStreamLabel << " :: " << msg;

    int N = logParams.size();
    if (N > 0)
    {
        outStream << " (";
        for (int i = 0; i < N; ++i)
        {
            outStream << logParams[i].key << ": [" << logParams[i].value << "]";
            if (i < N-1)
                outStream << ", ";
        }
        outStream << ")";
    }

    outStream << "\033[0m" << endl;
}

bool LogUtil::isLogTypeEnabled(LogType logType)
{
    return logEnabled[logType];
}

void LogUtil::setLogTypeEnabled(LogType logType, bool enabled)
{
    logEnabled[logType] = enabled;
}

void LogUtil::log(string msg, vector<LogParam> logParams, LogType logType)
{
    logProcedure(msg, logParams, "\033[34mLOG", clog, logType);
}

void LogUtil::error(string msg, vector<LogParam> logParams)
{
    logProcedure(msg, logParams, "\033[31mERROR", clog, LogType::ERROR);
}