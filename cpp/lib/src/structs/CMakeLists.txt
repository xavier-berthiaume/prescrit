add_library(structs SHARED)

add_library(prescrit::structs ALIAS structs)

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

target_link_libraries(structs
    PUBLIC utils
)

target_include_directories(structs
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
  TARGETS structs
  EXPORT structsTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  EXPORT structsTargets
  FILE prescritstructsTargets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/prescrit
)
