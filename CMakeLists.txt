cmake_minimum_required(VERSION 2.9)


set(MAIN HelloWorld)
set(PROJECT_NAME HelloWorld)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scripts/cmake)
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/${MAIN}.cpp)

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME}_lib ${SRC_FILES})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/${MAIN}.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)


###########################################
#				TESTING 				  #
###########################################

# Download and unpack googletest at configure time
configure_file(${CMAKE_MODULE_PATH}/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${MAIN}_test ${TEST_SRC_FILES})
target_link_libraries(${MAIN}_test ${MAIN}_lib)
target_link_libraries(${MAIN}_test gtest_main)
add_test(NAME test COMMAND ${MAIN}_test)


###########################################
#				COVERAGE 				  #
###########################################


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scripts/cmake)


include(CodeCoverage)

SET (CMAKE_C_FLAGS_INIT                "-Wall -std=c++11")
SET (CMAKE_C_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET (CMAKE_CXX_FLAGS_INIT                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG_INIT          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE_INIT        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")

SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

APPEND_COVERAGE_COMPILER_FLAGS()
SETUP_TARGET_FOR_COVERAGE_GCOVR_XML(
	NAME ${PROJECT_NAME}_coverage 
	EXECUTABLE ${MAIN}_test
	DEPENDENCIES ${MAIN}_lib)
    




