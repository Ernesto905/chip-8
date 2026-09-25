#include <cstdint>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>

void LoadProgram(char* file_name, std::vector<std::uint8_t>& memory); 

void LoadFont(std::vector<std::uint8_t>& memory); 
