cmake_minimum_required(VERSION 3.24)
project(DefExport)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    src/DefExport.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS /DEF:${CMAKE_CURRENT_LIST_DIR}/src/DefExport.def
    )
endif()
