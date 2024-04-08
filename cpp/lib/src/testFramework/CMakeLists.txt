add_library(testframework SHARED)

add_library(prescrit::testframework ALIAS testframework)

set_target_properties(testframework PROPERTIES
    PREFIX "lib"
    POSITION_INDEPENDENT_CODE ON
)

target_sources(testframework PRIVATE 
    "testframework.cpp"
)

target_link_libraries(testframework
    PUBLIC structs
)

target_include_directories(testframework
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
  TARGETS testframework
  EXPORT testframeworkTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  EXPORT testframeworkTargets
  FILE prescrittestframeworkTargets.cmake
  NAMESPACE prescrit::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/prescrit
)
