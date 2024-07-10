cmake_minimum_required(VERSION 3.24)
project(Sample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src
        ${CMAKE_CURRENT_LIST_DIR}/../DeclspecExport/include
        ${CMAKE_CURRENT_LIST_DIR}/../DefExport/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../build/DeclspecExport/Release/DeclspecExport.lib
        ${CMAKE_CURRENT_LIST_DIR}/../build/DefExport/Release/DefExport.lib
)

# copy DLL to output directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_LIST_DIR}/../build/DeclspecExport/Release/DeclspecExport.dll
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_LIST_DIR}/../build/DefExport/Release/DefExport.dll
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
