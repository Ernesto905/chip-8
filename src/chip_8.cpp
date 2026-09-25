#include "rom_loader.h"

int main(int argc, char* argv[]) {
  std::vector<std::byte> memory; // 4KB ; 4096B
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
  LoadFont(memory); 

  return 0;
}
