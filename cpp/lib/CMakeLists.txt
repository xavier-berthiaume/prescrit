cmake_minimum_required(VERSION 3.14)

project(prescrit-serializers LANGUAGES CXX)

set(version 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(serializers STATIC
    "src/patient.capnp.c++"
    "src/pharmacy_user.capnp.c++"
)
