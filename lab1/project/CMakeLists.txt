cmake_minimum_required(VERSION 3.23)

set(project "lab1")
project(${project})

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/directory)
link_directories(${CMAKE_SOURCE_DIR}/library)

set(${project}_SOURCES
        project.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} mymath)
target_link_libraries(${project} myproduct)
