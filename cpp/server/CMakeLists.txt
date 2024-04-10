cmake_minimum_required(VERSION 3.5)

project(prescrit-server VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(prescrit REQUIRED COMPONENTS utils structs network)
find_package(CapnProto REQUIRED)

add_executable(server main.cpp)

target_link_libraries(server
    PUBLIC prescrit::structs
    PUBLIC prescrit::network
    ${CAPNP_LIBRARIES}
)
