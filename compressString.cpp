#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>

std::string compressString(const std::string &a) {
    std::stringstream ss;
    char lastChar = a[0];
    int lastOccurences = 0;
    for(auto c : a) {
        if(c != lastChar) {
            ss << lastChar;
            ss << lastOccurences;
            lastChar = c;
            lastOccurences = 1;
        } else {
            ++lastOccurences;
        }
    }
    ss << lastChar;
    ss << lastOccurences;
    auto result = ss.str();
    return result.size() > a.size() ? a : result;
}

int main(int argc, char *argv[]) {
    if( argc != 2 ) {
        std::cout << "proper usage: compressString STR1" << std::endl;
        return 1;
    }
    auto result = compressString(argv[1]);
    std::cout << result << std::endl;
    return 0;
}
