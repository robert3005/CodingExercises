#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct node_t {
    int id;
    node_t * left;
    node_t * right;

    node_t(int id) : id(id) {}

    node_t(int id, node_t * left, node_t * right) : id(id), left(left), right(right) {}

    ~node_t() {
        if(left != nullptr) {
            delete left;
        }
        if(right != nullptr) {
            delete right;
        }
    }
} Node;

void printTree(Node * t) {
    function<void(Node *, int)> printTreeHelper = [&printTreeHelper] (Node * node, int indent) -> void {
        cout << string(indent * 2, ' ') << node->id << endl;
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

Node * lca(Node * t, Node * n, Node * m) {
    function<int(Node *, Node *, Node *, vector<Node *>&, int, int)> lcaHelper;
    lcaHelper = [&lcaHelper] (Node * t, Node * n, Node * m,
            vector<Node *> & path, int level, int curLevel) -> int {
        curLevel++;
        path.push_back(t);

        if(t->id == n->id || t->id == m->id) {
            if(level == -1) {
                level = curLevel;
            } else {
                path.pop_back();
                return level;
            }
        }

        if(t->left != nullptr) {
            int leftLevel = lcaHelper(t->left, n, m, path, level, curLevel);
            if(leftLevel != -1) {
                if(level == -1) {
                    level = leftLevel;
                } else {
                    path.pop_back();
                    return level;
                }
            }
        }

        if((int)path.size() <= level) {
            level--;
        }

        if(t->right != nullptr) {
            int rightLevel = lcaHelper(t->right, n, m, path, level, curLevel);
            if(rightLevel != -1) {
                if(level == -1) {
                    level = rightLevel;
                } else {
                    path.pop_back();
                    return level;
                }
            }
        }
        path.pop_back();

        return level;
    };
    vector<Node *> path = {};
    int resultLevel = lcaHelper(t, n, m, path, -1, -1);
    if(resultLevel == -1) {
        return nullptr;
    } else {
        return path[resultLevel];
    }
}

int main(int argc, char* argv[]) {
    Node * root = new Node(0);
    Node * t1 = new Node(1);
    Node * t2 = new Node(2);
    root->left = t1;
    root->right = t2;
    Node * t3 = new Node(3);
    Node * t4 = new Node(4);
    t1->left = t3;
    t1->right = t4;
    Node * t5 = new Node(5);
    t2->right = t5;
    Node * t6 = new Node(6);
    Node * t7 = new Node(7);
    t5->left = t6;
    t5->right = t7;
    Node * t8 = new Node(8);
    Node * t9 = new Node(9);
    t7->left = t8;
    t7->right = t9;

    printTree(root);
    Node * ancestor = lca(root, t5, t9);
    if(ancestor != nullptr) {
        cout << endl << ancestor->id << endl;
    } else {
        cout << endl << "Nodes " << t5->id << " and " << t9->id << " not found in tree" << endl;
    }
    delete root;
    return 0;
}
