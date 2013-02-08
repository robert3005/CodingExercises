#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <map>
#include <sstream>
#include <iterator>

template <class T>
std::string printVector(std::vector<T> list, std::stringstream & ss) {
	ss.str("");
	ss.clear();
	std::copy(list.begin(), list.end(), std::ostream_iterator<T>(ss, ", "));
	auto vectorS = ss.str();
	return vectorS.substr(0, vectorS.size() - 2);
}

template <class K>
std::vector<K> randomiseList(std::vector<K> list) {
	std::vector<K> shuffled(list);
	auto swap = [&shuffled] (const int i, const int j) {
		auto tmp = shuffled[i];
		shuffled[i] = shuffled[j];
		shuffled[j] = tmp;
	};

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution;

	for(int j = shuffled.size() - 1; j > 0; --j) {
  		distribution = std::uniform_int_distribution<int>(0, j);
  		int number = distribution(generator);
  		swap(number, j);
	}
	return shuffled;
}

template <class K>
void verifyRandomness(std::vector<K> list, int repetitions) {
	std::map<std::vector<K>,int> occCount;
	std::vector<K> shuffled;
	for(int i = 0; i < repetitions; i++) {
		shuffled = randomiseList<K>(list);
		occCount[shuffled]++;
	}
	std::stringstream ss;
	for(auto i : occCount) {
		auto vectorS = printVector<K>(i.first, ss);
		std::cout << vectorS << ": " << i.second << std::endl;
	}
}

int main(int argc, char * argv[]) {
	if(argc != 3) {
		std::cout << "Usage: " << argv[0] << " SIZE REPETITIONS" << std::endl;
		return 1;
	}
	std::vector<int> deck;
	for(int i = 0; i < atoi(argv[1]); i++) {
		deck.push_back(i);
	}
	verifyRandomness<int>(deck, atoi(argv[2]));
	return 0;
}