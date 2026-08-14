#include <iostream>
#include <string>
#include <vector>

void echo(std::vector<std::string> &tokens){
    for (int i=1 ;i< tokens.size();i++){
        std::cout<< tokens[i];
        if(i+1 < tokens.size()){
            std::cout<< " ";
        }
    }

    std::cout<< "\n";

}

std::vector<std::string> tokenize(std::string& input){

    std::vector<std::string>tokens;
    std::string current_token = "";

    for (int i=0; i<std::size(input);i++){
        if(input[i] == ' '){
            if(!current_token.empty()){
                tokens.push_back(current_token);
                current_token.clear();
            }
        }
        else{
            current_token += input[i];
        }
    }
    if(!current_token.empty()){
        tokens.push_back(current_token);
    }

    return tokens;

}

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // repl loop read evalute print loop
  std::string input = "";
  while(true) {
      std::cout<< "$ ";
      std::getline(std::cin,input);

      std::vector<std::string>command = tokenize(input);

      if(command.empty()){
          continue;
      }

      if(command[0] =="exit" && (command.size()==1)){
          break;
      }
      else if(command[0]=="echo" && (command.size()>=1)){
          echo(command);
      }
      else{
           std::cout<<command[0]<<": command not found\n";
      }

  }
}
