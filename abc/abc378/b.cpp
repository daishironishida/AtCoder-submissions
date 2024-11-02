#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> qr;

    for (int i = 0; i < N; i++) {
        int q, r;
        cin >> q >> r;
        qr.push_back(make_pair(q, r));
    }


    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int d, t;
        cin >> d >> t;
        int q = qr.at(d - 1).first;
        int r = qr.at(d - 1).second;

        int next = (t - r + q - 1) / q * q + r;
        cout << next << endl;
    }
}