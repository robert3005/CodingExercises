#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> board;

struct cell {
    int x;
    int y;

    cell(int x, int y) : x(x), y(y) {}
};

typedef cell * field;

bool isBoardValid(board &b) {
    auto allAtMostOnce = [] (vector<int> &elem) -> bool {
        bool valid = true;
        for(int v = 1; v < 10; v++) {
            valid = valid && count(elem.begin(), elem.end(), v) < 2;
        }
        return valid;
    };

    bool valid = true;
    for(int i = 0; i < b.size(); i+=3) {
        for(int j = 0; j < b[0].size(); j+=3) {
            vector<int> square = {
                b[i][j], b[i][j+1], b[i][j+2], b[i+1][j],
                b[i+1][j+1], b[i+1][j+2], b[i+2][j],
                b[i+2][j+1], b[i+2][j+2]
            };
            valid = valid && allAtMostOnce(square);
        }
    }

    for(int i = 0; i < b[0].size(); i++) {
        vector<int> column;
        for(int j = 0; j < b.size(); j++) {
            column.push_back(b[j][i]);
        }
        valid = valid && allAtMostOnce(column);
    }

    for(auto row : b) {
        valid = valid && allAtMostOnce(row);
    }

    return valid;
}

field findFirstEmpty(board &b) {
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            if(b[i][j] == 0) {
                return new cell(j, i);
            }
        }
    }

    return nullptr;
}

board * solveBoard(board &b) {
    board * newB = new vector<vector<int>>(b);
    field nextEmpty = findFirstEmpty(*newB);
    if(nextEmpty == nullptr) {
        return newB;
    }

    for(int value = 1; value < 10; value++) {
        (*newB)[nextEmpty->y][nextEmpty->x] = value;
        if(isBoardValid(*newB)) {
            board * newSolved = solveBoard(*newB);
            if(newSolved != nullptr) {
                return newSolved;
            }
        }
    }

    return nullptr;
}

int main(int argc, char * argv[]) {
    board values = {
        {0, 0, 7, 5, 8, 0, 0, 6, 0},
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 7, 9},
        {0, 4, 9, 8, 0, 6, 5, 1, 0},
        {6, 7, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 3, 0},
        {0, 6, 0, 0, 3, 2, 1, 0, 0}
    };
    board * solvedBoard = solveBoard(values);
    if(solvedBoard != nullptr) {
        for(auto row : *solvedBoard) {
            cout << " | ";
            for(auto value : row) {
                cout << value << " | ";
            }
            cout << endl;
        }
    }
    return 0;
}
