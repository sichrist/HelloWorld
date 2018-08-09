cmake_minimum_required(VERSION 2.9)

project (HelloWorld_test_project)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(hello ${SOURCES})

set(MY_URL "https://github.com/google/googletest/archive/master.zip")
set(MY_DOWNLOAD_PATH "${PROJECT_SOURCE_DIR}/build/gtest.zip")
set(MY_EXTRACTED_FILE "${PROJECT_SOURCE_DIR}/lib/gtest")

if (NOT EXISTS "${MY_DOWNLOAD_PATH}")
    file(DOWNLOAD "${MY_URL}" "${MY_DOWNLOAD_PATH}")
endif()

add_custom_command(
    OUTPUT ${MY_EXTRACTED_FILE}
    COMMAND  echo "HALLO"
    DEPENDS ${MY_DOWNLOAD_PATH}
    COMMENT "Unpacking ${MY_DOWNLOAD_PATH}"
    VERBATIM)


