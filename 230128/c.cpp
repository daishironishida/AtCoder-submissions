#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N != M + 1) {
        cout << "No";
        return 0;
    }

    vector<int> counts(N);
    unordered_map<int, vector<int> > maps;

    for (int i = 0; i < M; i++) {
        int next, prev;
        cin >> next >> prev;
        counts.at(next-1)++;
        counts.at(prev-1)++;

        maps[next].push_back(prev);
        maps[prev].push_back(next);
    }

    int edgeCount = 0;
    int edge1 = -1;
    for (int i = 0; i < N; i++) {
        if (counts.at(i) == 1) {
            edge1 = i+1;
            edgeCount++;
            if (edgeCount > 2) {
                cout << "No";
                return 0;
            }
            continue;
        }
        if (counts.at(i) == 2) {
            continue;
        }

        cout << "No";
        return 0;
    }

    // ループ検知
    vector<bool> seen(N);
    int prev, current, next;
    prev = -1;
    current = edge1;
    for (int i = 0; i < N-1; i++) {
        //cout << current << endl;
        seen.at(current-1) = true;
        vector<int> &nextVals = maps[current];
        for (int j = 0; j < nextVals.size(); j++) {
            if (nextVals.at(j) != prev) {
                next = nextVals.at(j);
                continue;
            }
        }

        if (seen.at(next-1)) {
            //cout << "found " << current << "," << next;
            cout << "No";
            return 0;
        }

        prev = current;
        current = next;
    }

    cout << "Yes";
}