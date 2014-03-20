#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector<int> &a, int i, int j) {
    auto tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void pushDown(vector<int> &a, int start, int end) {
    int root = start;
    while(root * 2 + 1 <= end) {
        int child = root * 2 + 1;
        int swapWith = root;
        if(a[swapWith] < a[child]) {
            swapWith = child;
        }
        if(child + 1 <= end && a[swapWith] < a[child + 1]) {
            swapWith = child + 1;
        }
        if(swapWith != root) {
            swap(a, root, swapWith);
            root = swapWith;
        } else{
            return;
        }
    }
}

void heapify(vector<int> &a) {
    int start = (a.size() - 2) / 2;
    while(start >= 0) {
        pushDown(a, start, a.size() - 1);
        start--;
    }
}

vector<int> heapSort(vector<int> &a) {
    int end = a.size() - 1;
    heapify(a);
    while(end > 0) {
        swap(a, end, 0);
        end--;
        pushDown(a, 0, end);
    }
    return a;
}

int main(int argc, char * argv[]) {
    vector<int> values = {45, 23, 1, 21, 4, 7, 96, 34};
    auto sortedValues = heapSort(values);
    cout << "sorted: ";
    for(auto v : sortedValues) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
