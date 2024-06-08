#include <bits/stdc++.h>

using namespace std;

void print(int N, long row, bool isCenter) {
    if (isCenter) {
        long max = pow(3, N);
        for (long i = 0; i < max; i++) {
            cout << '.';
        }
        return;
    }

    if (N == 0) {
        cout << '#';
        return;
    }

    long max = pow(3, N-1);
    bool nextIsCenter = row / max == 1;

    print(N-1, row % max, false);
    print(N-1, row % max, nextIsCenter);
    print(N-1, row % max, false);
}

int main() {
    int N;
    cin >> N;

    long max = pow(3, N);

    for (long i = 0; i < max; i++) {
        print(N, i, false);
        cout << endl;
    }
}