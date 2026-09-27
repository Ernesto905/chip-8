include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/063de7e9578f82b369302001269680b4b1553359.zip # V1.18.0
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE  
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(TestRomLoader
test_rom_loader.cpp)

target_link_libraries(TestRomLoader
  PRIVATE
    GTest::gtest_main
    core 
)

include(GoogleTest)
gtest_discover_tests(TestRomLoader)

