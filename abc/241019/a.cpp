#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> t(N);

    for (int i = 0; i < N; i++) {
        cin >> t.at(i);
    }

    int sum = 0;
    int last = -C;
    for (int i = 0; i < N; i++) {
        if (t.at(i) - last >= C) {
            sum++;
            last = t.at(i);
        }
    }

    cout << sum;

}