#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>


void LoadProgram(char* file_name, std::vector<std::byte>& memory) {
  std::ifstream ch8_file(file_name, std::ios::binary);
  ch8_file.unsetf(std::ios::skipws);
  std::streampos file_size;

  ch8_file.seekg(0, std::ios::end);
  file_size = ch8_file.tellg();
  ch8_file.seekg(0, std::ios::beg);

  std::vector<std::byte> program;
  program.reserve(file_size);
  ch8_file.read(reinterpret_cast<char *>(std::data(program)), file_size);

  memory.insert(memory.end(), program.begin(), program.end());
}

void LoadFont(std::string file_name, std::vector<std::byte>& memory) {
  std::vector<std::uint8_t> hexadecimals;
  std::string line;
  std::ifstream ch8_file(file_name, std::ios::binary);
  while(std::getline(ch8_file, line)) {
    std::stringstream ss(line);
    std::string str_hex;
    while(std::getline(ss, str_hex)) {
      std::uint8_t hex = static_cast<std::uint8_t>(std::stoul(str_hex, nullptr, 16));
      hexadecimals.push_back(hex);
    }
  }
}

int main(int argc, char* argv[]) {
  std::string font_file = "./font";
  std::byte ZERO{0}; 
  std::vector<std::byte> memory(200, ZERO); // 4KB ; 4096B
  std::vector<bool> display(256, 0); // 64 x 32 pixels ; 256B
  std::uint16_t reg_pc;
  std::uint16_t reg_i;
  std::stack<std::uint16_t> stack; 
  std::uint8_t delay_timer;
  std::uint8_t sound_timer;
  std::byte reg_general_purpose[16]; 

  if (argc != 2) {
    std::cout << "Your program received " << argc - 1 << " arguments but expected 1." << std::endl;
    std::cout << "Example:" << std::endl;
    std::cout << "\t./chip-8 tests/IBM_Logo_test.ch8" << std::endl;
    return 1;
  }

  // TODO: Write unit tests for these two knuckleheads before continuing
  LoadProgram(argv[1],memory);
  LoadFont(font_file, memory); 

  return 0;
}
