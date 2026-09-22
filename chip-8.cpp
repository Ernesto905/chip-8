#include <iosfwd>
#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>


std::vector<std::byte> ReadProgram(char* file_name) {
  std::ifstream ch8_file(file_name, std::ios::binary);
  ch8_file.unsetf(std::ios::skipws);
  std::streampos file_size;

  ch8_file.seekg(0, std::ios::end);
  file_size = ch8_file.tellg();
  ch8_file.seekg(0, std::ios::beg);

  std::vector<std::byte> program;
  program.reserve(file_size);
  ch8_file.read(reinterpret_cast<char *>(std::data(program)), file_size);
  
  return program;
}

int main(int argc, char* argv[]) { 
  if (argc != 2) {
    std::cout << "Your program received " << argc - 1 << " arguments but expected 1." << std::endl;
    std::cout << "Example:" << std::endl;
    std::cout << "\t./chip-8 tests/IBM_Logo_test.ch8" << std::endl;
    return 1;
  }
  std::vector<std::byte> program = ReadProgram(argv[1]);

  // TODO: create datastructures for our stack, display, registers, etc.

  return 0;
}
