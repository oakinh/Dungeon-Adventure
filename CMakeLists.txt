cmake_minimum_required(VERSION 3.10)
project(OS-Task-Scheduler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(dungeon-adventure PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB SOURCES "src/*.cpp")

add_executable(dungeon-adventure ${SOURCES})