# console commands for quick reference
# cmake .. -DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/5.14.1/
cmake_minimum_required(VERSION 3.5)

project(keyswift LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set (keyswiftLib_src
 ${PROJECT_SOURCE_DIR}/src/mainwindow.cpp
 ${PROJECT_SOURCE_DIR}/src/QtKeyToTamilKey.cpp)

set (keyswiftLib_hdr
 ${PROJECT_SOURCE_DIR}/include/mainwindow.h
 ${PROJECT_SOURCE_DIR}/include/QtKeyToTamilKey.h)

set (keyswiftLib_ui ${PROJECT_SOURCE_DIR}/forms/mainwindow.ui)
set (keyswiftBin_src ${PROJECT_SOURCE_DIR}/src/main.cpp)

qt5_wrap_cpp(keyswiftLib_hdr_moc ${keyswiftLib_hdr})
qt5_wrap_ui(keyswiftLib_ui_moc ${keyswiftLib_ui})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_SOURCE_DIR}/include)
include_directories (${PROJECT_BINARY_DIR})

add_library(keyswiftLib SHARED
  ${keyswiftLib_src}
  ${keyswiftLib_hdr_moc}
  ${keyswiftLib_ui_moc}
  )

target_link_libraries (keyswiftLib Qt5::Widgets)

add_executable(keyswift ${keyswiftBin_src})

target_link_libraries (keyswift keyswiftLib)