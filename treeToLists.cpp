#include <iostream>
#include <vector>

struct btree {
	int value;
	struct btree * leftChild;
	struct btree * rightChild;
};

typedef struct btree * btree_t;

std::vector<std::vector<btree_t>> treeToList(btree_t tree) {
	std::vector<btree_t> incoming;
	std::vector<btree_t> outgoing;
	incoming.push_back(tree);
	std::vector<std::vector<btree_t>> nodesLists;
	while(!incoming.empty()) {
		nodesLists.push_back(incoming);
		for( auto node : incoming ) {
			if(node->leftChild != nullptr) {
				outgoing.push_back(node->leftChild);
			}
			if(node->rightChild != nullptr) {
				outgoing.push_back(node->rightChild);
			}
		}
		incoming = outgoing;
		outgoing.clear();
	}
	return nodesLists;
}

int main(int argc, char * argv[]) {
	btree_t tree = new btree();
	tree->value = 6;
	tree->rightChild = new btree();
	tree->leftChild = new btree();
	tree->rightChild->value = 7;
	tree->leftChild->value = 3;
	tree->leftChild->rightChild = new btree();
	tree->leftChild->leftChild = new btree();
	tree->leftChild->rightChild->value = 59;
	tree->leftChild->leftChild->value = 2;
	auto treeLists = treeToList(tree);
	for(auto i : treeLists) {
		std::cout << "{";
		for(auto j : i) {
			std::cout << j->value << ", ";
		}
		std::cout << "}, ";
	}
	return 0;
}