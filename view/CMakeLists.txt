cmake_minimum_required(VERSION 3.5)

project(FurryViewer2 VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(icon)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/FurryViewer2")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS OpenGLWidgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        glwidget.h
        glwidget.cpp
        Settings.h
        Settings.cc
        gif/gif.h
        ../model/Facade.cc
        ../model/Facade.h
        ../model/FacadeOperationResult.cc
        ../model/FacadeOperationResult.h
        ../model/Facet.cc
        ../model/Facet.h
        ../model/NormalizationParametrs.cc
        ../model/NormalizationParametrs.h
        ../model/Parser.cc
        ../model/Parser.h
        ../model/Scene.cc
        ../model/Scene.h
        ../model/Vertex.cc
        ../model/Vertex.h
        ../model/Strategy.h
        ../model/Strategy.cc

        ../controller.h
        ../controller.cc

#        ../resources/resources.qrc
#        ../resources/icons/icon.png
#        ../resources/icons/icon.ico
#        ../resources/icons/icon.icns
#        ../resources/styles/back.png

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(FurryViewer2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(FurryViewer2 SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(FurryViewer2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(FurryViewer2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(FurryViewer2 PRIVATE Qt${QT_VERSION_MAJOR}::OpenGL)
target_link_libraries(FurryViewer2 PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)

set_target_properties(FurryViewer2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set_source_files_properties(../resources/icons/icon.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(FurryViewer2)
endif()

add_compile_options("-Wall -Wextra -Wpedantic -Werror")
