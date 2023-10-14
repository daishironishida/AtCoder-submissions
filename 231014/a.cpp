#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    int val = a[0];
    for (int x : a) {
        if (x != val) {
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;

}