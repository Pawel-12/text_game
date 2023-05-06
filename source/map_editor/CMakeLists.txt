cmake_minimum_required(VERSION 3.24)
project(map_editor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -static-libstdc++ -static-libgcc")



add_executable(map_editor ${SOURCES})

set_target_properties(map_editor PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/../../bin")
