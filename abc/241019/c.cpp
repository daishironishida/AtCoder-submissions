#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    vector<long long> b(N-1);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    for (int i = 0; i < N-1; i++) {
        cin >> b.at(i);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int diff = 1;
    long long size = -1;
    for (int i = N-2; i >= 0; ) {
        //cout << a.at(i + diff) << "," << b.at(i) << endl;
        if (a.at(i + diff) > b.at(i)) {
            //cout << "doesn't fit" << endl;
            size = a.at(i + diff);
            diff--;
            if (diff < 0) {
                cout << -1;
                return 0;
            }
        } else {
            i--;
        }
    }
    if (size == -1) {
        size = a.at(0);
    }
    cout << size;

}