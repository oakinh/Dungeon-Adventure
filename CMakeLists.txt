cmake_minimum_required(VERSION 3.10)
project(Dungeon-Adventure)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS 
    "${PROJECT_SOURCE_DIR}/src/**/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

add_executable(Dungeon-Adventure ${SOURCES})

target_include_directories(Dungeon-Adventure PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
