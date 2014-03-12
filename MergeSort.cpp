#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &a, vector<int> &helper, int left, int middle, int right) {
    for(int i = left; i <= right; i++) {
        helper[i] = a[i];
    }

    int helperLeft = left;
    int helperRight = middle + 1;
    int current = left;

    while(helperLeft <= middle && helperRight <= right) {
        if(helper[helperLeft] <= helper[helperRight]) {
            a[current] = helper[helperLeft];
            helperLeft++;
        } else {
            a[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }

    int remaining = middle - helperLeft;
    for(int i = 0; i <= remaining; i++) {
        a[current + i] = helper[helperLeft + i];
    }
}

vector<int> mergeSort(vector<int> &a, vector<int> &helper, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, helper, left, mid);
        mergeSort(a, helper, mid + 1, right);
        merge(a, helper, left, mid, right);
    }
    return a;
}

vector<int> mergeSort(vector<int> &a) {
    vector<int> helper(a.size());
    return mergeSort(a, helper, 0, a.size() - 1);
}

int main(int argc, char * argv[]) {
    vector<int> values = {45, 23, 1, 21, 4, 7, 96, 34};
    auto sortedValues = mergeSort(values);
    cout << "sorted: ";
    for(auto v : sortedValues) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
