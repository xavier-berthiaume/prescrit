cmake_minimum_required(VERSION 3.5)

project(prescrit-server VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CapnProto REQUIRED)

set(SERIALIZERS_DIR "${CMAKE_SOURCE_DIR}/src/lib")
add_library(serializers STATIC IMPORTED)
set_target_properties(serializers PROPERTIES IMPORTED_LOCATION ${SERIALIZERS_DIR}/build/libserializers.a)

add_executable(server 
    src/main.cpp
    src/prescrit_core_impl.cpp
    src/prescrit_core_impl.h
)

target_link_libraries(server
    PRIVATE serializers
    ${CAPNP_LIBRARIES}
)
