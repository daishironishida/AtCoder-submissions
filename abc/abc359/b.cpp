#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(2 * N);

    for (int i = 0; i < 2 * N; i++) {
        cin >> a.at(i);
    }

    int count = 0;
    int twoPrev = -1;
    int prev = -1;
    for (int i = 0; i < 2 * N; i++) {
        if (a.at(i) == twoPrev) {
            count++;
        }
        twoPrev = prev;
        prev = a.at(i);
    }

    cout << count;
}