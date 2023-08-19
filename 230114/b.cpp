#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char> > a;
    for (int i = 0; i < h; i++) {
        vector<char> vec(w);
        a.push_back(vec);
    }

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            cin >> a.at(r).at(c);
        }
    }

    int q;
    cin >> q;

    // process
    int rowOffset = 0;
    int colOffset = 0;
    bool inOrder = true;

    for (int i = 0; i < q; i++) {
        int R, C;
        cin >> R >> C;

        if (inOrder) {
            rowOffset = (rowOffset + R - 1) % h;
            colOffset = (colOffset + C - 1) % w;
        } else {
            rowOffset = (rowOffset - R + 1 + h) % h;
            colOffset = (colOffset - C + 1 + w) % w;
        }
        inOrder = !inOrder;
    }

    // print result
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            int rowIndex, colIndex;

            if (inOrder) {
                rowIndex = (r + rowOffset) % h;
                colIndex = (c + colOffset) % w;
            } else {
                rowIndex = (-r + rowOffset + h) % h;
                colIndex = (-c + colOffset + w) % w;
            }

            cout << a.at(rowIndex).at(colIndex);
        }
        cout << endl;
    }
}