cmake_minimum_required(VERSION 3.6)
project(backroom CXX C)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "/opt/homebrew/Cellar")

message(STATUS "####################################################")
message(STATUS "PROJECT_NAME = ${PROJECT_NAME}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_ROOT = ${CMAKE_ROOT}")
message(STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
message(STATUS "####################################################")

add_library(Code STATIC
    ${PROJECT_SOURCE_DIR}/src/Code/ByteCode.cpp
    ${PROJECT_SOURCE_DIR}/src/Code/ProgramStateDebug.cpp
    ${PROJECT_SOURCE_DIR}/src/Code/SourceCode.cpp
    ${PROJECT_SOURCE_DIR}/src/Interpreter/Interpreters.cpp
)
target_include_directories(Code PUBLIC
    ${PROJECT_SOURCE_DIR}/include/Code
    ${PROJECT_SOURCE_DIR}/include/Interpreter
)

add_library(Util STATIC
    ${PROJECT_SOURCE_DIR}/src/Util/StringUtil.cpp
    ${PROJECT_SOURCE_DIR}/src/Util/LogUtil.cpp
)
target_include_directories(Util PUBLIC
    ${PROJECT_SOURCE_DIR}/include/Util
)

target_link_libraries(Code PRIVATE Util)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Code Util)

message(STATUS "####################################################")
message(STATUS "DONE")
message(STATUS "####################################################")