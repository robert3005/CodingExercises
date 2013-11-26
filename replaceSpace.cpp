#include <iostream>
#include <algorithm>
#include <string.h>

char * replaceSpaces(const std::string &a) {
    int spaces = std::count(a.begin(), a.end(), ' ');
    char *buffer = new char [a.size() + 2 * spaces];
    char *currLocation = buffer;
    const char *orignalString = a.c_str();
    while(*orignalString) {
        if(*orignalString == ' ') {
            *currLocation++ = '%';
            *currLocation++ = '2';
            *currLocation++ = '0';
        } else {
            *currLocation++ = *orignalString;
        }
        orignalString++;
    }
    return buffer;
}

int main(int argc, char *argv[]) {
    if( argc != 2 ) {
        std::cout << "proper usage: replaceSpace STR1" << std::endl;
        return 1;
    }
    auto result = replaceSpaces(argv[1]);
    std::cout << result << std::endl;
    return 0;
}
