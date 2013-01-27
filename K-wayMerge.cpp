#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>

auto kWayMerge(std::vector<std::vector<int>> unmergedList) -> std::vector<int> {
	std::vector<int> merged;
	std::vector<std::pair<int,int>> heap;
	int j = 0;
	std::for_each(unmergedList.begin(), unmergedList.end(), [&heap, &j] (std::vector<int> kList) {
		heap.push_back(std::make_pair(0, j));
		j++;
	});
	auto heapComparator = [&unmergedList] (const decltype(heap)::value_type &a, const decltype(heap)::value_type &b) -> bool {
		return unmergedList[a.second][a.first] > unmergedList[b.second][b.first];
	};
	make_heap(heap.begin(), heap.end(), heapComparator);
	while(!heap.empty()) {
		std::pop_heap(heap.begin(), heap.end(), heapComparator);
		auto smallest = heap.back();
		heap.pop_back();

		merged.push_back(unmergedList[smallest.second][smallest.first]);

		if(smallest.first + 1 < unmergedList[smallest.second].size()) {
			heap.push_back(std::make_pair(smallest.first + 1, smallest.second));
			std::push_heap(heap.begin(), heap.end(), heapComparator);
		}

	}
	return merged;
}

int main(int argc, char * argv[]) {
	std::vector<std::vector<int>> unsorted = {{1,2,3,4}, {5,7,9}, {12,14}};
	std::cout << "Unsorted list: ";
	for(auto i : unsorted) {
		std::cout << "{";
		for(auto j : i) {
			std::cout << j << ", ";
		}
		std::cout << "}, ";
	}
	std::cout << std::endl;
	auto sorted = kWayMerge(unsorted);
	std::cout << "Sorted: ";
	for(auto i : sorted) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
	return 0;
}