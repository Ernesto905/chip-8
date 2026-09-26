cmake_minimum_required(VERSION 3.16)
project(Chip-8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
target_link_libraries(chip_8 PRIVATE SDL3::SDL3)
