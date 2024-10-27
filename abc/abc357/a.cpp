#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> h(N);

    for (int i = 0; i < N; i++) {
        cin >> h.at(i);

        int newM = M - h.at(i);
        if (newM < 0) {
            cout << i;
            exit(0);
        }
        M = newM;
    }
    cout << N;

}