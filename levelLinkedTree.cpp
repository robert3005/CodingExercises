#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::mt19937 generator(std::random_device{}());
std::uniform_real_distribution<double> distribution(0, 1);
std::function<double()> rnd = std::bind(distribution, generator);

typedef struct node_t {
    node_t * left;
    node_t * right;
    node_t * sameLevelSuccessor;
    double value;
} Node;

Node * levelLinkTree(Node * t) {
    auto lastSuccessors = std::vector<Node *>();
    std::function<void(Node *, int)> linkLevels = [&lastSuccessors, &linkLevels]
            (Node * node, int level) -> void {
        if(lastSuccessors.size() > level) {
            lastSuccessors[level]->sameLevelSuccessor = node;
            lastSuccessors[level] = node;
        } else {
            lastSuccessors.push_back(node);
        }

        if(node->left != nullptr) {
            linkLevels(node->left, level + 1);
        }
        if(node->right != nullptr) {
            linkLevels(node->right, level + 1);
        }
    };
    linkLevels(t, 0);
    return t;
}

Node * createRandomTree(int maxDepth) {
    Node * root = new Node();
    root->value = rnd();
    if (maxDepth != 0) {
        // Random left child
        if(rnd() < 0.5) {
            root->left = createRandomTree(maxDepth - 1);
        }
        // Random right child
        if(rnd() < 0.5) {
            root->right = createRandomTree(maxDepth - 1);
        }
    }
    return root;
}

void printTree(Node * t) {
    std::function<void(Node *, int)> printTreeHelper = [&printTreeHelper] (Node * node, int indent) -> void {
        std::cout << std::string(indent * 2, ' ') << node->value << std::endl;
        if(node->left != nullptr) {
            printTreeHelper(node->left, indent + 1);
        }
        if(node->right != nullptr) {
            printTreeHelper(node->right, indent + 1);
        }
    };
    if(t != nullptr) {
        printTreeHelper(t, 0);
    }
}

void printTreeByLevel(Node * t) {
    auto successor = t;
    Node * leftMostChild = nullptr;
    while(successor != nullptr) {
        std::cout << successor->value << " ";
        if(leftMostChild == nullptr) {
            if(successor->left != nullptr) {
                leftMostChild = successor->left;
            } else if(successor->right != nullptr) {
                leftMostChild = successor->right;
            }
        }
        successor = successor->sameLevelSuccessor;
    }
    std::cout << std::endl;
    if(leftMostChild != nullptr) {
        printTreeByLevel(leftMostChild);
    }
}

int main(int argc, char* argv[]) {
    Node * root = createRandomTree(20);
    printTree(root);
    std::cout << std::endl;
    root = levelLinkTree(root);
    printTreeByLevel(root);
    return 0;
}
