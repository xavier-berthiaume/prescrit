set(SERIALIZERS_DIR "${CMAKE_SOURCE_DIR}/src/lib/src")

add_executable(server 
    main.cpp
    prescrit_core_impl.cpp
    prescrit_core_impl.h
)

target_include_directories(server PUBLIC ${SERIALIZERS_DIR})

target_link_libraries(server
    PRIVATE serializers
    ${CAPNP_LIBRARIES}
)
