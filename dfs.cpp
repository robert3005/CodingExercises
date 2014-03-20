#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct graph_t {
    int value;
    set<graph_t *> adj;
};

typedef graph_t * graph;

graph dfs(graph G, int k) {
    set<graph> visited;
    function<graph(graph)> search;
    search = [&visited, &search, k] (graph node) -> graph {
        if(node == nullptr) {
            return nullptr;
        }
        if(node->value == k) {
            return node;
        }

        visited.insert(node);
        graph found = nullptr;
        for(graph n : node->adj) {
            // Not visited
            if(*visited.find(n) == *visited.end()) {
                graph findX = search(n);
                found = findX != nullptr ? findX : found;
            }
        }
        return found;
    };

    return search(G);
}

int main(int argc, char * argv[]) {
    graph a = new graph_t();
    a->value = 1;
    graph b = new graph_t();
    b->value = 2;
    graph c = new graph_t();
    c->value = 3;
    graph d = new graph_t();
    d->value = 4;

    a->adj.insert(b);
    a->adj.insert(c);
    b->adj.insert(c);
    b->adj.insert(d);
    c->adj.insert(a);
    c->adj.insert(d);
    d->adj.insert(a);
    d->adj.insert(c);

    graph node = dfs(a, 2);
    if(node != nullptr) {
        cout << "node " << node->value << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}
