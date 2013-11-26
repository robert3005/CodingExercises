#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <string.h>

bool isPermutation(const std::string &a, const std::string &b) {
    std::map<char, int> counts;
    std::for_each(a.begin(), a.end(), [&counts](char letter) -> void {
        if(counts.count(letter)) {
            counts[letter]++;
        } else {
            counts[letter] = 1;
        }
    });
    std::for_each(b.begin(), b.end(), [&counts](char letter) -> void {
        if(counts.count(letter)) {
            counts[letter]--;
        } else {
            counts[letter] = -1;
        }
    });
    return std::all_of(counts.begin(), counts.end(), [](decltype(counts)::value_type &elem) -> bool {
        return elem.second == 0;
    });
}

bool isPermutationSort(const std::string &a, const std::string &b) {
    std::string aCopy(a);
    std::string bCopy(b);
    std::sort(aCopy.begin(), aCopy.end());
    std::sort(bCopy.begin(), bCopy.end());
    return aCopy.compare(bCopy) == 0;
}

int main(int argc, char *argv[]) {
    if( argc != 3 ) {
        std::cout << "proper usage: isPermutation STR1 STR2" << std::endl;
        return 1;
    }
    bool result = isPermutation(argv[1], argv[2]) && isPermutationSort(argv[1], argv[2]);

    if (result) {
        std::cout << "The strings are permutations of each other." << std::endl;
    } else {
        std::cout << "The strings are not permutations of each other." << std::endl;
    }

    return 0;
}
