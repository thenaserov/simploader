cmake_minimum_required(VERSION 3.16)

project(simploader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        adddownload.h
        adddownload.cpp
        adddownload.ui
        downloader.h
        downloader.cpp
        downloadhistoryentry.h
        downloadhistoryentry.h
        downloadprogresswidget.h
        downloadprogresswidget.cpp

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(simploader
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        adddownload.h adddownload.cpp adddownload.ui
        downloader.h downloader.cpp
        downloadprogresswidget.h downloadprogresswidget.cpp
        downloadhistoryentry.h
        resources.qrc
    )

else()
    if(ANDROID)
        add_library(simploader SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(simploader
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(simploader PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.simploader)
endif()
set_target_properties(simploader PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS simploader
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(simploader)
endif()
