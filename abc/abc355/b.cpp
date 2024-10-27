#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    vector<int> b(M);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < M; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int a_index = 0;
    int b_index = 0;
    bool is_a = false;

    while (a_index < N && b_index < M) {
        if (a.at(a_index) == b.at(b_index)) {
            cout << "error";
            return 1;
        } else if (a.at(a_index) < b.at(b_index)) {
            if (is_a) {
                cout << "Yes";
                return 0;
            }
            a_index++;
            is_a = true;
        } else {
            b_index++;
            is_a = false;
        }
    }

    if (a_index < N-1) {
        cout << "Yes";
    } else {
        cout << "No";
    }

}