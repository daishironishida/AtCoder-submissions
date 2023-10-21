#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    bool positive = true;
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        if (a.at(i) == 0) {
            cout << "0";
            exit(0);
        }
        if (a.at(i) < 0) {
            positive = !positive;
        }
    }

    if (positive) {
        cout << "+";
    } else {
        cout << "-";
    }
}