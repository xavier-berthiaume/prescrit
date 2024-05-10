cmake_minimum_required(VERSION 3.14)

project(prescrit-serializers LANGUAGES CXX)

set(version 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)

set_target_properties(serializers PROPERTIES 
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(serializers PUBLIC src)
