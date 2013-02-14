#include <iostream>

struct nodeList {
	int value;
	struct nodeList * next;
};

typedef struct nodeList * node_t;

bool detectLoop(node_t node) {
	node_t slow = node, fast1 = node, fast2 = node;
	if(fast2->next == nullptr || fast2->next->next == nullptr) {
		return false;
	}
	while(slow && (fast1 = fast1->next) && (fast2 = fast2->next->next)) {
		if(fast2->next == nullptr || fast2->next->next == nullptr) {
			return false;
		}
		if(slow == fast1 || slow == fast2) {
			return true;
		}
		slow = slow->next;
	}
	return false;
}

int main(int argc, char * argv[]) {
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
	node3->next = node;
	std::cout << detectLoop(node) << std::endl;
	return detectLoop(node);
}