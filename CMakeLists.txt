cmake_minimum_required(VERSION 3.16)
project(chip-8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

add_executable(chip_8 WIN32
  src/chip_8.cpp
  src/rom_loader.cpp
)

target_link_libraries(chip_8 PRIVATE SDL3::SDL3)
