#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> a, int x) {
    if(a[0] >= x || !a.size()) {
        return 0;
    }
    int left = 0;
    int right = a.size();
    int mid;
    while(right - left > 1) {
        mid = (right + left) / 2;
        if(a[mid] < x) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

int main(int argc, char * argv[]) {
    vector<int> values = {0, 1, 3, 5, 34, 43, 63, 99};
    int val = 101;
    cout << "value: " << val << " found at position " << binarySearch(values, val) << endl;
    return 0;
}
