cmake_minimum_required(VERSION 3.5)

project(prescrit-server VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CapnProto REQUIRED)
find_package(kj REQUIRED)
find_package(prescrit REQUIRED)

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/x86_64-linux-gnu/)

if(CapnProto_FOUND)
    message(STATUS "Found Cap'n Proto: ${CapnProto_INCLUDE_DIRS}")
    include_directories(${CapnProto_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Cap'n Proto not found.")
endif()

add_executable(server main.cpp)

target_link_libraries(server
    PUBLIC capnp
    PUBLIC kj
    PUBLIC prescrit::network
    PUBLIC prescrit::structs
)
