cmake_minimum_required(VERSION 3.10)
project(Algorithm)

set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
file(MAKE_DIRECTORY ${BUILD_DIR})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_COMMANDS_DIR "${BUILD_DIR}")

file(MAKE_DIRECTORY ${BUILD_DIR}/.cache)

include_directories(${CMAKE_SOURCE_DIR}/.vscode/bits)

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Searching for source files...")

file(GLOB_RECURSE SOURCES 
    "Solutions/Baekjoon/**/*.cpp"
    "Solutions/Algos/_Tests/**/*.cpp"
)

message(STATUS "Found source files: ${SOURCES}")

foreach(SOURCE ${SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    get_filename_component(SOURCE_DIR ${SOURCE} DIRECTORY)
    
    message(STATUS "========== Processing New File ==========")
    message(STATUS "Processing source file: ${SOURCE}")
    message(STATUS "Target name before replace: ${TARGET_NAME}")
    message(STATUS "Source directory: ${SOURCE_DIR}")
    
    string(REPLACE " " "_" TARGET_NAME ${TARGET_NAME})
    message(STATUS "Target name after replace: ${TARGET_NAME}")
    
    set(TEST_DIR "${SOURCE_DIR}/test_cases/${TARGET_NAME}")
    message(STATUS "Creating test directory at: ${TEST_DIR}")
    file(MAKE_DIRECTORY ${TEST_DIR})
    
    set(INPUT_FILE "${TEST_DIR}/input.txt")
    message(STATUS "Checking for input file at: ${INPUT_FILE}")
    if(NOT EXISTS "${INPUT_FILE}")
        message(STATUS "Creating input.txt file")
        file(WRITE "${INPUT_FILE}" "")
    endif()
    
    message(STATUS "Creating executable for: ${TARGET_NAME}")
    add_executable(${TARGET_NAME} ${SOURCE})
    
    message(STATUS "Setting output directory to: ${TEST_DIR}")
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${TEST_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${TEST_DIR}"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${TEST_DIR}"
    )
    message(STATUS "========== File Processing Complete ==========\n")
endforeach() 