#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<int, unordered_set<int>> x2y;
    unordered_map<int, unordered_set<int>> y2x;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        if (!x2y.count(x)) {
            x2y[x] = unordered_set<int>();
        }
        if (!y2x.count(x)) {
            y2x[y] = unordered_set<int>();
        }
        x2y[x].insert(y);
        y2x[y].insert(x);
    }

    vector<int> result(N);

    int first = -1;
    int first_count = 0;
    int i = 1;
    while (i <= N) {
        if (!y2x.count(i)) {
            first = i;
            first_count++;
        }
        i++;
    }

    if (first < 0 || first_count > 1) {
        cout << "No";
        exit(0);
    }

    int current = first;
    for (int i = 1; i < N; i++) {
        int next_count = 0;
        int next = -1;
        for (int del : x2y[current]) {
            y2x[del].erase(current);
            if (y2x[del].size() == 0) {
                next_count++;
                next = del;
            }
        }
        if (next_count > 1 || next < 0) {
            cout << "No";
            exit(0);
        }
        result[current-1] = i;
        current = next;
    }
    // last
    result[current-1] = N;

    cout << "Yes" << endl;
    for (int res : result) {
        cout << res << " ";
    }

}