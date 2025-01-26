cmake_minimum_required(VERSION 3.16)
project(Alu_GUI VERSION 0.1 LANGUAGES CXX)

# Enable Qt auto-features
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core)

# Add DPI library
add_library(dpi_alu SHARED
  dpi/dpi_alu.cpp
)

# Link Qt Core and Widgets to dpi_alu
target_link_libraries(dpi_alu PRIVATE
  Qt${QT_VERSION_MAJOR}::Core     # For QProcess
  Qt${QT_VERSION_MAJOR}::Widgets  # For QMessageBox
)

# Include Questa headers
target_include_directories(dpi_alu PRIVATE
  "E:/programmer_tools/questa/include"
)

# Remove "lib" prefix for Windows
if(WIN32)
  set_target_properties(dpi_alu PROPERTIES
    OUTPUT_NAME "dpi_alu"
    PREFIX ""
  )
endif()

# Create executable
qt_add_executable(Alu_GUI
  MANUAL_FINALIZATION
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
)

# Link libraries to executable
target_link_libraries(Alu_GUI PRIVATE
  Qt${QT_VERSION_MAJOR}::Widgets
  dpi_alu  # Link the DPI library
)

# Copy DLL to build directory (Windows)
if(WIN32)
  add_custom_command(TARGET Alu_GUI POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
      $<TARGET_FILE:dpi_alu>
      $<TARGET_FILE_DIR:Alu_GUI>
  )
endif()

# Finalize Qt
if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(Alu_GUI)
endif()
