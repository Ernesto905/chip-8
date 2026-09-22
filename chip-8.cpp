#include <stdio.h>

int main(int argc, char *argv[]) 
{ 
  if (argc != 2) {
    printf("Your program received %d arguments but expected 1.\n\n", argc - 1); 
    printf("Example:\n");
    printf("\t./chip-8 tests/IBM_Logo_test.ch8\n");
    return 1;
  }
  
  /*TODO && Notes
   * - [] read its bytes
   *      to use plain char or to not use plain char, that is the question ; 
   *      https://stackoverflow.com/questions/13642381/c-c-why-to-use-unsigned-char-for-binary-data
   * - [] create data structures 
   * - [] the switch statement 
   * - [] load it into memory (Remember to start at addr 200)
   * */

  FILE *ch8_file_ptr;
  unsigned char ch8_program[1024]; // we'll assume the program is 1024 bytes for now
  
  ch8_file_ptr = fopen(argv[1], "r");
  fgets(ch8_program, 1024, ch8_file_ptr);

  return 0;
}
