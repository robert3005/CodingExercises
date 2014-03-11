#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> sortByPalindromes(vector<string> words) {
    map<string, vector<string>> sortedWords;
    for(auto word : words) {
        auto origWord(word);
        sort(word.begin(), word.end());
        sortedWords[word].push_back(origWord);
    }

    return sortedWords;
}

int main(int argc, char * argv[]) {
  vector<string> words = {"fasa", "aba", "baa", "kayak", "yakak", "asfa"};
  auto sortedWords = sortByPalindromes(words);
  cout << "Words by palindromes" << endl;
  for(auto group : sortedWords) {
    cout << "Word: " << group.first << endl;
    for(auto word : group.second) {
        cout << word << endl;
    }
    cout << endl;
  }
  return 0;
}
