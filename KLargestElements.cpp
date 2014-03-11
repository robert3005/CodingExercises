#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>

auto kLargestElements(std::vector<int> list, int k) -> std::vector<int> {
  std::vector<int> klargest;
  make_heap(klargest.begin(), klargest.end(), std::greater<int>());
  for(auto elem : list) {
    if(klargest.size() < k) {
      klargest.push_back(elem);
      std::push_heap(klargest.begin(), klargest.end(), std::greater<int>());
    } else {
      std::pop_heap(klargest.begin(), klargest.end(), std::greater<int>());
      auto smallest = klargest.back();
      klargest.pop_back();

      if(elem > smallest) {
        klargest.push_back(elem);
      } else {
        klargest.push_back(smallest);
      }
      std::push_heap(klargest.begin(), klargest.end(), std::greater<int>());
   }
  }
  return klargest;
}

int main(int argc, char * argv[]) {
  std::vector<int> list = {1,2,3,4,5,7,9,12,14};
  auto klargest = kLargestElements(list, 3);
  std::cout << "K Largest Elements: ";
  for(auto i : klargest) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  return 0;
}
