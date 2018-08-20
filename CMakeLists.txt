cmake_minimum_required(VERSION 2.9)

set(PROJECT_NAME HelloWorld)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/src/HelloWorld.cpp)

set(CMAKE_CXX_STANDARD 11)

add_library(HelloWorld_lib ${SRC_FILES})
add_executable(HelloWorld ${PROJECT_SOURCE_DIR}/src/HelloWorld.cpp)

target_link_libraries(HelloWorld HelloWorld_lib)


###########################################
#				TESTING 				  #
###########################################

# Download and unpack googletest at configure time
configure_file(${PROJECT_SOURCE_DIR}/CMakeLists.txt.in googletest-download/CMakeLists.txt)
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
add_executable(testrun ${TEST_SRC_FILES})
target_link_libraries(testrun HelloWorld_lib)
target_link_libraries(testrun gtest_main)
add_test(NAME test COMMAND testrun)
