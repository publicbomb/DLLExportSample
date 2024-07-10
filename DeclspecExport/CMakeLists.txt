cmake_minimum_required(VERSION 3.24)
project(DeclspecExport)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    src/DeclspecExport.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        DECLSPEC_EXPORTS
)
