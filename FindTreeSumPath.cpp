#include <iostream>
#include <vector>
#include <algorithm>

struct btree {
	int value;
	struct btree * leftChild;
	struct btree * rightChild;
};

typedef struct btree * btree_t;

std::vector<std::vector<int>> findSumPath(btree_t t1, int N) {
	std::vector<std::vector<int>> res;
	std::function<void(btree_t, std::vector<int>)> sumPath;
	sumPath = [&res, &N, &sumPath] (btree_t t1, std::vector<int> buffer) -> void {
		if(t1 == nullptr) {
			return;
		}
		buffer.push_back(t1->value);
		int tmp = N;
		for (auto it = --buffer.end(); it != --buffer.begin();  --it ) {
			tmp -= *it;
			if(tmp == 0) {
				res.push_back(std::vector<int>(it, buffer.end()));
			}
		}

		sumPath(t1->leftChild, std::vector<int>(buffer));
		sumPath(t1->rightChild, std::vector<int>(buffer));
	};
	std::vector<int> buffer;
	sumPath(t1, buffer);
	return res;
}

int main(int argc, char * argv[]) {
	btree_t t1 = new btree();
	t1->value = 1;
	btree_t t2 = new btree();
	t2->value = 1;
	t1->rightChild = t2;
	btree_t t3 = new btree();
	t3->value = 2;
	t1->leftChild = t3;
	auto sumPaths = findSumPath(t1, 3);
	for(auto i : sumPaths) {
		std::cout << "{";
		for(auto j : i) {
			std::cout << j << ", ";
		}
		std::cout << "}, ";
	}
	std::cout << std::endl;
	return 0;
}