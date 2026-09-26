add_subdirectory(core)

add_executable(chip_8 WIN32
  chip_8.cpp
)

target_link_libraries(chip_8 PRIVATE SDL3::SDL3)
target_link_libraries(chip_8
  PRIVATE 
    core
)
