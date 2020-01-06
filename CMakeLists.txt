cmake_minimum_required(VERSION 3.10)

project(learn_git_cmake VERSION 0.0.1)

set(TARGET first)
set(SOURCE_DIR src)

file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(${TARGET} ${SOURCES})
find_package(Boost REQUIRED COMPONENTS program_options)
target_link_libraries(${TARGET} ${Boost_LIBRARIES})
target_include_directories(${TARGET} PUBLIC ${Boost_INCLUDE_DIRS})

target_compile_features(${TARGET} PUBLIC cxx_std_11)
