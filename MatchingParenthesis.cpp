#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

auto matchingParenthesis(int k) -> std::vector<std::string> {
  std::vector<std::string> bracketList;
  std::function<void(int,int,std::string)> brackets;
  brackets = [&brackets, &bracketList] (int l, int r, std::string buffer) -> void {
    if(r < l || l < 0) {
      return;
    }
    if(l == 0 && r == 0) {
      bracketList.push_back(buffer);
    } else {
      if(l > 0) {
        brackets(l - 1, r, buffer + "(");
      }
      if(r > 0) {
        brackets(l, r - 1, buffer + ")");
      }
    }
  };
  brackets(k, k, "");
  return bracketList;
}

int main(int argc, char * argv[]) {
  if( argc != 2 ) {
    std::cout << "USAGE: " << argv[0] << " NUMBER" << std::endl;
    return 1;
  }
  int count;
  std::istringstream ( argv[1] ) >> count;
  auto bracketPairs = matchingParenthesis(count);
  for(auto i : bracketPairs) {
    std::cout << i << std::endl;
  }
  return 0;
}