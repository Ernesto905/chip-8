# add executable 
add_executable(TestRomLoader)
# add sources  
target_sources(TestRomLoader
  PRIVATE
    test_rom_loader.cpp
)
# link the rom_loader cpp file to your new test target 
target_link_libraries(TestRomLoader
  PRIVATE
    
)
# create a function for running your test 
function()
  
endfunction()
# call the function on two empty example 
#
#
# TODO: look at google standard guide and shadps4 and cmake guide. 
# How do do you name files, and cmakelist targets?
