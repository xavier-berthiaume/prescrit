cmake_minimum_required(VERSION 3.14)

project(prescritStructs LANGUAGES CXX)

set(version 0.1)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/prescrit 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

add_library(structs SHARED
	"src/patient.cpp"
	"src/prescriber.cpp"
	"src/prescription.cpp"
    "src/normal.cpp"
    "src/magistral.cpp"
    "src/prescription-list.cpp"
	"src/insurance.cpp"
	"src/product.cpp"
    "src/premade.cpp"
    "src/medication.cpp"
    "src/bandage.cpp"
    "src/syringe.cpp"
	"src/time.cpp"
	"src/phonenumbers.cpp"
	"src/units.cpp"
	"src/ingredient.cpp"
	"src/location.cpp"
    "src/testframework.cpp"
)

add_library(prescrit::structs ALIAS structs)

target_include_directories(structs
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_definitions(structs PRIVATE PRESCRIT_STRUCTS_LIBRARY)

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
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)

option(BUILD_TESTS "Build tests along with source" OFF)

if(${BUILD_TESTS})
  add_subdirectory(tests)
endif()
