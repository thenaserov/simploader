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
# Android OpenSSL 3 support (Qt-provided prebuilt)
# ----------------------------------------------------------------------
if(ANDROID)
    message(STATUS "Attaching OpenSSL 3 libraries for Android")

    set(QT_ANDROID_OPENSSL "/Users/thenaserov/Library/Android/sdk/android_openssl/ssl_3")
    set(ANDROID_ABIS arm64-v8a armeabi-v7a x86 x86_64)

    set(ANDROID_OPENSSL_LIBS "")
    foreach(ABI ${ANDROID_ABIS})
        if(EXISTS "${QT_ANDROID_OPENSSL}/${ABI}/libcrypto_3.so" AND EXISTS "${QT_ANDROID_OPENSSL}/${ABI}/libssl_3.so")
            list(APPEND ANDROID_OPENSSL_LIBS
                "${QT_ANDROID_OPENSSL}/${ABI}/libcrypto_3.so"
                "${QT_ANDROID_OPENSSL}/${ABI}/libssl_3.so"
            )
        endif()
    endforeach()

    # Attach OpenSSL libraries to the APK
    set_property(TARGET simploader PROPERTY ANDROID_EXTRA_LIBS "${ANDROID_OPENSSL_LIBS}")
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
