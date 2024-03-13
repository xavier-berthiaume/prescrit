cmake_minimum_required(VERSION 3.14)

project(prescritStructs LANGUAGES CXX)

set(version 0.1)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

install(FILES src/globalDefinitions.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_library(utils SHARED
	"src/utils/phonenumbers.cpp"
	"src/utils/time.cpp"
)

add_library(prescrit::utils ALIAS utils)

target_include_directories(utils
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_definitions(utils PRIVATE PRESCRIT_UTILS_LIBRARY)

install(
    FILES src/structDefinitions.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  TARGETS utils 
  EXPORT utilsTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    FILES src/utilDefinitions.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  EXPORT utilsTargets
  FILE prescritutilsTargets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/prescrit
)

add_library(structs SHARED
	"src/structs/patient.cpp"
	"src/structs/prescriber.cpp"
	"src/structs/prescription.cpp"
	"src/structs/insurance.cpp"
	"src/structs/product.cpp"
)

add_library(prescrit::structs ALIAS structs)

target_include_directories(structs
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(structs
  PRIVATE prescrit::utils
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
    FILES src/structDefinitions.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
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
