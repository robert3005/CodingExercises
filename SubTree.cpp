#include <iostream>

struct btree {
	int value;
	struct btree * leftChild;
	struct btree * rightChild;

	bool operator==(const struct btree * const t2) const {
		return 	t2 != nullptr &&
				value == t2->value &&
				leftChild == t2->leftChild &&
				rightChild == t2->rightChild;
	};
};

typedef struct btree * btree_t;

bool subTree(btree_t t1, btree_t t2) {
	std::function<bool(btree_t, btree_t)> findSubTree;
	findSubTree = [&findSubTree] (btree_t t1, btree_t t2) -> bool {
		return 	(t1 == nullptr && t2 == nullptr) || (t1 != nullptr && (*t1 == t2 ||
				findSubTree(t1->leftChild, t2) ||
				findSubTree(t1->rightChild, t2)));
	};

	return findSubTree(t1, t2);
}

int main(int argc, char * argv[]) {
	btree_t t1 = new btree();
	t1->value = 1;
	btree_t t2 = new btree();
	t2->value = 1;
	btree_t t3 = new btree();
	t3->value = 2;
	t2->leftChild = t3;
	std::cout << subTree(t1, t2) << std::endl;
 	return 0;
}