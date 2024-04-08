# Define the library as SHARED
add_library(network SHARED)

# Alias the library to prescrit::network
add_library(prescrit::network ALIAS network)

# Set properties for the library
set_target_properties(network PROPERTIES
    PREFIX "lib"
    POSITION_INDEPENDENT_CODE ON
)

# Set the source files for the library
target_sources(network PRIVATE
    "rpc_interface.capnp.c++"
)

# Link against the structs library
target_link_libraries(network PUBLIC structs)

# Set include directories for the library
target_include_directories(network
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install the library and export its targets
install(
    TARGETS network
    EXPORT networkTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the export file for the library
install(
    EXPORT networkTargets
    FILE prescritnetworkTargets.cmake
    NAMESPACE prescrit::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/prescrit
)
