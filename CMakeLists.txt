cmake_minimum_required(VERSION 3.10)
project(DetectTheLineEnding)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
        message(FATAL_ERROR "GCC version must be at least 9.0")
    endif()
endif()

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CRLF src/CRLF.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(CRLF PRIVATE stdc++fs)
endif()
