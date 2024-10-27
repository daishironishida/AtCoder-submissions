#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;

    if (N < M) {
        cout << 0 << endl;
        exit(0);
    }

    int result = (N - M) / P + 1;
    cout << result << endl;
}