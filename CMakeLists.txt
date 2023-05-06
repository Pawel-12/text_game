cmake_minimum_required(VERSION 3.24)
project(text_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -static-libstdc++ -static-libgcc")

file(
        GLOB_RECURSE SOURCES LIST_DIRECTORIES true
        ${CMAKE_CURRENT_LIST_DIR}/source/cpp/*.cpp
)

include_directories(source/headers/)

add_executable(text_game ${SOURCES})

set_target_properties(text_game PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/bin")

add_subdirectory(google_test)

add_subdirectory(source/map_editor)


