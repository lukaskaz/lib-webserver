cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

project(webserver)

include(cmake/dependencies.cmake)
include(cmake/flags.cmake)

add_subdirectory(examples)

include_directories(inc)
file(GLOB SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} ${SOURCES})
