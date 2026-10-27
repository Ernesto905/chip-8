#include <fstream>
#include <iterator>
#include <rom_loader.h>
/*
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <vector>
#include <cstdint>

*/
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


/*
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

 * */

#include <gtest/gtest.h>

TEST(LoadProgramTest, HandlesHappyPath) {
  char test_binary_file[] = "mytestfile.ch8"; 
  std::vector<uint8_t> expected_values = {0x74, 0x65, 0x73, 0x74, 0x69, 0x6E, 0x67}; // "testing"
  std::ofstream out_file(test_binary_file, std::ios::binary);
  out_file.write(reinterpret_cast<const char*>(expected_values.data()), std::size(expected_values));
  out_file.close();


  std::vector<std::uint8_t> mock_memory(4096, 0);
  LoadProgram(test_binary_file, mock_memory);
  for (int i = 0; i < expected_values.size(); i++) {
    EXPECT_EQ(mock_memory[200 + i], expected_values[i]);
  }
  

  std::remove(test_binary_file);
}
