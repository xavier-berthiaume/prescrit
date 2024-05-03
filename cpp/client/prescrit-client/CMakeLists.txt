cmake_minimum_required(VERSION 3.5)

project(prescrit-client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(CapnProto REQUIRED)

set(SERIALIZERS_DIR "${CMAKE_SOURCE_DIR}/lib")
add_library(serializers STATIC IMPORTED)
set_target_properties(serializers PROPERTIES IMPORTED_LOCATION ${SERIALIZERS_DIR}/build/libserializers.a)
include_directories(${SERIALIZERS_DIR})

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        lockscreen/lockscreen.cpp
        lockscreen/lockscreen.h
        lockscreen/lockscreen.ui
        lockscreen/createuserwindow.cpp
        lockscreen/createuserwindow.h
        lockscreen/createuserwindow.ui
        rpcclient.cpp
        rpcclient.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(prescrit-client
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET prescrit-client APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(prescrit-client SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(prescrit-client
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(prescrit-client
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE serializers
    ${CAPNP_LIBRARIES}
)

set_target_properties(prescrit-client PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS prescrit-client
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(prescrit-client)
endif()
