#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> count(2 * N + 2);

    for (int i = 1; i < T+1; i++) {
        int a;
        cin >> a;

        int row = (a-1) % N;
        int col = a / N;


        if (++count.at(row) == N) {
            cout << i;
            return(0);
        }
        if (++count.at(N + col) == N) {
            cout << i;
            return(0);
        }
        if (row == col) {
            if (++count.at(2*N) == N) {
                cout << i;
                return(0);
            }
        } 
        if ((N-row-1) == col) {
            if (++count.at(2*N+1) == N) {
                cout << i;
                return(0);
            }
        }


    }

    cout << -1;

}