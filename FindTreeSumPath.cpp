#include <iostream>
#include <vector>

struct btree {
	int value;
	struct btree * leftChild;
	struct btree * rightChild;
};

typedef struct btree * btree_t;

std::vector<std::vector<int>> findSumPath(btree_t t1, int N) {
	std::vector<std::vector<int>> res;
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