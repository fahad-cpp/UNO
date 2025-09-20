cmake_minimum_required(VERSION 3.10)
project(Uno)

add_subdirectory(core)
add_executable(Uno Uno.cpp)
target_link_libraries(Uno PRIVATE core)