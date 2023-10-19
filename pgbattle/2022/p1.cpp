#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // falseが表
    vector<bool> senbei(N, false);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++) {
            senbei[j-1] = !senbei[j-1];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (senbei[i]) ans++;

    }

    cout << ans << endl;


}