#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    set<string> T;

    for (int i = 0; i < N; i++) {
        cin >> S.at(i);
    }
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        T.insert(t);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        string test = S.at(i).substr(3, 3);
        if (T.count(test)) {
            count++;
        }
    }
    cout << count;
}