#include <iostream>
#include <sstream>

struct nodeList {
	int value;
	struct nodeList * next;
};

typedef struct nodeList * node_t;

node_t nthToLast(node_t node, int n) {
	node_t head = node;
	node_t result = node;
	for(int i = n; i > 0; i--) {
		head = head->next;
	}
	while (head->next != nullptr) {
		result = result->next;
		head = head->next;
	}
	return result;
}

int main(int argc, char* argv[]) {
	if(argc != 2) {
		return 1;
	}
	node_t node = new nodeList();
	node->value = 0;
	node_t node1 = new nodeList();
	node1->value = 1;
	node->next = node1;
	node_t node2 = new nodeList();
	node2->value = 2;
	node1->next = node2;
	node_t node3 = new nodeList();
	node3->value = 3;
	node2->next = node3;
	node3->next = nullptr;
	int nth;
	std::istringstream ( argv[1] ) >> nth;
	std::cout << nthToLast(node, nth)->value << std::endl;
	return 0;
}