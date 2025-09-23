cmake_minimum_required(VERSION 3.10)
project(Uno)

add_subdirectory(core)
file(GLOB GAME_SOURCES "*.cpp")
add_executable(Uno ${GAME_SOURCES})
target_link_libraries(Uno PRIVATE core)