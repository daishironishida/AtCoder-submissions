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
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int x = 0;
    int y = 0;

    unordered_set<long long> history;
    long long startHash = (long long) N * (2 * N + 1) + N;
    history.insert(startHash);
    for (int i = 0; i < N; i++) {
        char move = S[i];

        if (move == 'R') {
            x += 1;
        } else if (move == 'L') {
            x -= 1;
        } else if (move == 'U') {
            y += 1;
        } else if (move == 'D') {
            y -= 1;
        }

        long long hash = (long long)(x + N) * (2 * N+1) + y + N;

        if (history.count(hash)) {
            cout << "Yes";
            exit(0);
        }
        history.insert(hash);
    }
    cout << "No";

}