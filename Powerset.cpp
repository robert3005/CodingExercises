#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printSet(set<int> &s) {
    cout << "set: ";
    if(s.size() == 0) {
        cout << "{}";
    }
    for(auto elem : s) {
        cout << elem << ", ";
    }
    cout << endl;
}

void printPwrSet(set<set<int> *> &pwrs) {
    for(auto subSet : pwrs) {
        printSet(*subSet);
    }
}

set<set<int> *> powerset(set<int> &s) {
    set<set<int> *> powerSet;
    if(s.size() == 0) {
        set<int> * emp = new set<int>();
        powerSet.insert(emp);
        return powerSet;
    }

    set<int> subset(next(s.begin()), s.end());

    auto subSets = powerset(subset);
    powerSet.insert(subSets.begin(), subSets.end());

    auto withSubSets = powerset(subset);
    for(auto subS : withSubSets) {
        subS->insert(*s.begin());
    }
    powerSet.insert(withSubSets.begin(), withSubSets.end());

    return powerSet;
}


int main(int argc, char * argv[]) {
    set<int> s = {0, 1, 2, 3};
    auto pwrs = powerset(s);
    cout << "subsets: " << pwrs.size() << endl;
    printPwrSet(pwrs);
    return 0;
}
