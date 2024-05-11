cmake_minimum_required(VERSION 3.14)

project(prescrit-server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CapnProto REQUIRED)

set(SERIALIZERS_DIR "${CMAKE_SOURCE_DIR}/lib")

add_executable(server main.cpp)

target_sources(server PUBLIC
    "prescrit_core_impl.cpp"
)

target_link_libraries(server
    PRIVATE "${SERIALIZERS_DIR}/build/libserializers.a"
    ${CAPNP_LIBRARIES}
)
