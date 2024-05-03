set(SERIALIZERS_DIR "${CMAKE_SOURCE_DIR}/src/lib")
add_library(serializers STATIC IMPORTED)
set_target_properties(serializers PROPERTIES IMPORTED_LOCATION ${SERIALIZERS_DIR}/build/libserializers.a)
target_include_directories(serializers INTERFACE ${SERIALIZERS_DIR})

add_executable(server 
    main.cpp
    prescrit_core_impl.cpp
    prescrit_core_impl.h
)

target_link_libraries(server
    PRIVATE serializers
    ${CAPNP_LIBRARIES}
)
