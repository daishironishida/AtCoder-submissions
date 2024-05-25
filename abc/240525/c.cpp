#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    cin >> N, T;
    vector<int> count(2 * N + 2);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        int row = (a-1) % N;
        int col = a / N;


        if (count.at(row)++ == N) {
            cout << i;
        }
        if (count.at(N + col)++ == N) {
            cout << i;
        }
        if (row == col) {
            if (count.at(2*N)++ == N) {
                cout << i;
            }
        } 
        if ((N-row) == col) {
            if (count.at(2*N+1)++ == N) {
                cout << i;
            }
        }
    }

    cout << -1;

}