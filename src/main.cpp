#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // repl loop read evalute print loop
  std::string input = "";
  while(true) {
      std::cout<< "$ ";
      std::getline(std::cin,input);
      std::cout<< input<<": command not found\n";
  }
}
