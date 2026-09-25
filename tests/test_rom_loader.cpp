// #include "rom_loader.h"
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <vector>
#include <cstdint>

/* Tests todo
 * 
 * load program
 * - happy path 
 * - bad file name (does not exist)
 *
 * load rom
 * - happy path 
 *
 * */


void TestLoadProgram() {
  // Arrange act assert 
  std::vector<std::uint8_t> mock_memory; 
  const char* mock_file = "../roms/BC_test.ch8";  

  LoadProgram(mock_file, mock_memory);
}

void TestLoadProgramBadFile() {
  // Arrange act assert 
  std::vector<std::uint8_t> mock_memory; 
  const char* mock_file = "asdf";  

  LoadProgram(mock_file, mock_memory);
}

void TestLoadRom() {
  // Arrange act assert 
  std::vector<std::uint8_t> correct_memory;
  std::vector<std::uint8_t> mock_memory;

  LoadRom(mock_memory);

  assert (correct_memory == mock_memory);
}

int main() {
    std::cout << "Running tests..." << std::endl;
    TestLoadProgram();
    TestLoadProgramBadFile();
    TestLoadRom();
    return 0;
}

