# Define the library as SHARED
add_library(structs SHARED)

# Alias the library to prescrit::structs
add_library(prescrit::structs ALIAS structs)

# Set properties for the library
set_target_properties(structs PROPERTIES
    PREFIX "lib"
    POSITION_INDEPENDENT_CODE ON
)

# Set the source files for the library
target_sources(structs PRIVATE
    "patient.cpp"
    "prescriber.cpp"
    "prescription.cpp"
    "normal.cpp"
    "magistral.cpp"
    "prescription-list.cpp"
    "patient-file.cpp"
    "insurance.cpp"
    "product.cpp"
    "premade.cpp"
    "medication.cpp"
    "bandage.cpp"
    "syringe.cpp"
    "ingredient.cpp"
    "user.cpp"
)

# Link against the utils library
target_link_libraries(structs PUBLIC prescrit::utils)

# Set include directories for the library
target_include_directories(structs
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install the library and export its targets
install(
    TARGETS structs
    EXPORT structsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the export file for the library
install(
    EXPORT structsTargets
    FILE prescritstructsTargets.cmake
    NAMESPACE prescrit::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/prescrit
)
