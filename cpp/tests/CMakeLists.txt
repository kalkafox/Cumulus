cmake_minimum_required(VERSION 3.23)

project(cumulus-test)

# Add the src directory for all other CMakeLists.txt files that run with this

include_directories(../src)

set(CMAKE_CXX_STANDARD 20)

add_executable(cumulus-test src/tests.cpp)

enable_testing()

add_test(NAME cumulus-test COMMAND cumulus-test)
