#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "SourceCode.h"
#include "ByteCode.h"
#include "LogUtil.h"

using namespace std;

int main(void)
{
    LogUtil::log("\n\n--------------- START ---------------", {}, LogUtil::LogType::CORE);

    int status = -1;

    status = parseSourceCode("sourceCode.txt", "byteCode.txt");
    if (status != 0)
        return status;

    status = runByteCode("byteCode.txt");
    if (status != 0)
        return status;

    LogUtil::log("\n--------------- END ---------------", {}, LogUtil::LogType::CORE);
    return status;
}