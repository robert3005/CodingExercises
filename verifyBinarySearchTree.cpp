#include <iostream>
#include <utility>
#include <limits>
#include <algorithm>
#include <string>

struct treeNode {
	int value;
	struct treeNode * rightChild;
	struct treeNode * leftChild;
};

typedef struct treeNode * treeNode_t;

bool verifyBinarySearchTree(treeNode_t tree) {
	auto updateMax = [] (std::pair<int,int> range, int newMax) -> std::pair<int,int> {
		return std::make_pair(range.first, std::min(newMax, range.second));
	};
	auto updateMin = [] (std::pair<int,int> range, int newMin) -> std::pair<int,int> {
		return std::make_pair(std::max(newMin, range.first), range.second);
	};
	std::function<bool(treeNode_t, std::pair<int,int>)> treeInRange;
	treeInRange = [updateMax,updateMin,&treeInRange] (treeNode_t tree, std::pair<int,int> range) -> bool {
		bool leftWithinRange = true, rightWithinRange = true, valueWithinRange;

		valueWithinRange = tree->value >= range.first && tree->value <= range.second;

		if(tree->leftChild != nullptr) {
			leftWithinRange = treeInRange(tree->leftChild, updateMax(range, tree->value));
		}

		if(tree->rightChild != nullptr) {
			rightWithinRange = treeInRange(tree->rightChild, updateMin(range, tree->value));
		}

		return valueWithinRange && leftWithinRange && rightWithinRange;
	};
	return treeInRange(tree->leftChild, std::make_pair(std::numeric_limits<int>::min(), tree->value))
		&& treeInRange(tree->rightChild, std::make_pair(tree->value, std::numeric_limits<int>::max()));
}

int main(int argc, char* argv[]) {
	treeNode_t tree = new treeNode();
	tree->value = 6;
	tree->rightChild = new treeNode();
	tree->leftChild = new treeNode();
	tree->rightChild->value = 7;
	tree->leftChild->value = 3;
	tree->leftChild->rightChild = new treeNode();
	tree->leftChild->leftChild = new treeNode();
	tree->leftChild->rightChild->value = 59;
	tree->leftChild->leftChild->value = 2;
	bool validTree = verifyBinarySearchTree(tree);
	std::string resultMessage;
	if (validTree) {
		resultMessage = "This is a valid Binary Search Tree";
	} else {
		resultMessage = "This is not a valid Binary Search Tree";
	}
	std::cout << resultMessage << std::endl;
	delete tree->leftChild->rightChild;
	delete tree->leftChild->leftChild;
	delete tree->rightChild;
	delete tree->leftChild;
	delete tree;
	return 0;
}