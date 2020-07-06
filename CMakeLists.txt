#-DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/
#cmake .. -DCMAKE_PREFIX_PATH=/usr/local/Cellar/qt/
cmake_minimum_required(VERSION 3.5)

project(KeySwift LANGUAGES CXX)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set (KeySwiftLib_src ${PROJECT_SOURCE_DIR}/*.cpp)
set (KeySwiftLib_hdr ${PROJECT_SOURCE_DIR}/*.h)
set (KeySwiftLib_ui ${PROJECT_SOURCE_DIR}/mainwindow.ui)
set (KeySwiftBin_src ${PROJECT_SOURCE_DIR}/main.cpp)

qt5_wrap_cpp(KeySwiftLib_hdr_moc ${KeySwiftLib_hdr})
qt5_wrap_ui(KeySwiftLib_ui_moc ${KeySwiftLib_ui})

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

add_library(KeySwiftLib SHARED
  ${KeySwiftLib_src}
  ${KeySwiftLib_hdr_moc}
  ${KeySwiftLib_ui_moc}
  )

target_link_libraries (KeySwiftLib Qt5::Widgets)

add_executable(KeySwift ${KeySwiftBin_src})

target_link_libraries (KeySwift KeySwiftLib)