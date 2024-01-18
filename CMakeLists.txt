cmake_minimum_required(VERSION 3.10)

project(advent_2023)

file(GLOB SOURCES "*.cpp")

foreach(SOURCE ${SOURCES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE} NAME_WE)

    add_executable(${EXECUTABLE_NAME} ${SOURCE})
endforeach()