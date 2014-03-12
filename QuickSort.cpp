#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void swap(vector<int> &a, int i, int j) {
    auto tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(vector<int> &a, int left, int right) {
    int pivotIndex = (left + right) / 2;
    int pivot = a[pivotIndex];
    swap(a, pivotIndex, right);
    int storeIndex = left;
    for(int i = left; i < right; i++) {
        if(a[i] <= pivot) {
            swap(a, i, storeIndex);
            storeIndex++;
        }
    }
    swap(a, storeIndex, right);
    return storeIndex;
}

vector<int> quickSort(vector<int> &a, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, right);
    }
    return a;
}

vector<int> quickSort(vector<int> &a) {
    return quickSort(a, 0, a.size());
}

int main(int argc, char * argv[]) {
    vector<int> values = {45, 23, 1, 21, 4, 7, 96, 34};
    auto sortedValues = quickSort(values);
    cout << "sorted: ";
    for(auto v : sortedValues) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
