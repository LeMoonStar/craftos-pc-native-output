cmake_minimum_required(VERSION 3.10)

project(native_output VERSION 1.0.0 DESCRIPTION "A plugin for CraftOS-PC which provides functions to send stdout output.")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(Lua51 REQUIRED)

include_directories(/usr/local/include ${LUA_INCLUDE_DIR})


add_library(native_output SHARED src/native_output.cpp)

target_link_libraries(native_output ${LUA_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
