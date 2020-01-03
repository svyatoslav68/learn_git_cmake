cmake_minimum_required(VERSION 3.10)

project(learn_git_cmake VERSION 0.0.1)

set(TARGET first)
set(SOURCE_DIR src)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(${TARGET} ${SOURCES})
