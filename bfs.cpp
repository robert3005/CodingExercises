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

graph bfs(graph G, int k) {
    vector<graph> queue;
    set<graph> visited;
    visited.insert(G);
    if(G == nullptr) {
        return nullptr;
    }

    if(G->value == k) {
        return G;
    }
    queue.push_back(G);
    graph result = nullptr;
    while(queue.size()) {
        graph n = queue.back();
        queue.pop_back();
        for(graph adj : n->adj) {
            if(*visited.find(adj) == *visited.end()) {
                queue.push_back(adj);
                visited.insert(adj);
                result = adj->value == k ? adj : result;
            }
        }
    }
    return result;
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

    graph node = bfs(a, 2);
    if(node != nullptr) {
        cout << "node " << node->value << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}
