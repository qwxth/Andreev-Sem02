cmake_minimum_required(VERSION 3.10)
project(lab4 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(mystack_lib STATIC
    MyStack.cpp
)

target_include_directories(mystack_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(lab4
    main.cpp
)

target_link_libraries(lab4 PRIVATE
    mystack_lib
)
