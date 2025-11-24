cmake_minimum_required(VERSION 3.16)

project(simploader VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------------------------------------------------------------------
# Find Qt modules
# ----------------------------------------------------------------------
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

# ----------------------------------------------------------------------
# Project sources
# ----------------------------------------------------------------------
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    adddownload.cpp
    adddownload.h
    adddownload.ui
    downloader.h
    downloader.cpp
    downloadprogresswidget.h
    downloadprogresswidget.cpp
    downloadhistoryentry.h
    resources.qrc
)

# ----------------------------------------------------------------------
# Create executable/library depending on platform
# ----------------------------------------------------------------------
qt_add_executable(simploader
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(simploader PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
)

# ----------------------------------------------------------------------
# Android OpenSSL 3 support (Recommended Method)
# ----------------------------------------------------------------------
if(ANDROID)
    message(STATUS "Downloading and attaching OpenSSL 3 libraries for Android")

    # Use FetchContent to download the KDAB repository with prebuilt OpenSSL libs
    include(FetchContent)
    FetchContent_Declare(
        android_openssl
        DOWNLOAD_EXTRACT_TIMESTAMP true
        # This URL points to the repository containing the prebuilt libs and helper CMake script
        URL https://github.com/KDAB/android_openssl/archive/refs/heads/master.zip
    )
    FetchContent_MakeAvailable(android_openssl)

    # Include the helper script provided by the repository
    include(${android_openssl_SOURCE_DIR}/android_openssl.cmake)

    # Use the helper function to link the libraries to your target
    # This function handles the multi-ABI linking and setting of the ANDROID_EXTRA_LIBS property
    add_android_openssl_libraries(simploader)

endif()

# ----------------------------------------------------------------------
# App bundle properties
# ----------------------------------------------------------------------
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.simploader)
endif()

set_target_properties(simploader PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# ----------------------------------------------------------------------
# Installation rules
# ----------------------------------------------------------------------
include(GNUInstallDirs)

install(TARGETS simploader
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# ----------------------------------------------------------------------
# Finalize executable
# ----------------------------------------------------------------------
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(simploader)
endif()
