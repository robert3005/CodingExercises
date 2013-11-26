#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>

struct btree {
  int value;
  struct btree * parent;
  struct btree * leftChild;
  struct btree * rightChild;
};

typedef struct btree * btree_t;

btree_t leftMostChild(btree_t tree) {
  btree_t leftMostChild = tree->leftChild;
  while(leftMostChild->leftChild != nullptr) {
    leftMostChild = leftMostChild->leftChild;
  }
  return leftMostChild;
}

btree_t nextInOrderNode(btree_t tree) {
  if(tree != nullptr) {
    btree_t nextNode;
    if(tree->parent == nullptr || tree->rightChild != nullptr) {
      nextNode = leftMostChild(tree->rightChild);
    } else {
      while((nextNode = tree->parent) != nullptr) {
        if(nextNode->leftChild == tree) {
          break;
        }
        tree = nextNode;
      }
    }
    return nextNode;
  }
  return nullptr;
}

int main(int argc, char * argv[]) {
  btree_t t1 = new btree();
  t1->value = 1;
  btree_t t2 = new btree();
  t2->value = 3;
  t1->rightChild = t2;
  t2->parent = t1;
  btree_t t3 = new btree();
  t3->value = 2;
  t1->leftChild = t3;
  t3->parent = t1;
  btree_t t4 = new btree();
  t4->value = 5;
  t4->parent = t3;
  t3->rightChild = t4;
  auto nextNode = nextInOrderNode(t4);
  std::cout << "Node: " << nextNode->value << std::endl;
  return 0;
}