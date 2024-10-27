#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> sets(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        sets.at(i).first = a;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        sets.at(i).second = b;
    }

    // sort by first
    sort(sets.begin(), sets.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    std::multimap<int, int> b2a;
    for (int r = 0; r < K - 1; r++) {
        b2a.insert({sets.at(r).second, sets.at(r).first});
    }

    ll min = __LONG_LONG_MAX__;

    for (int r = K-1; r < N; r++) {
        ll sum = sets[r].second;
        for (int i = 0; i < K - 1; i++) {
            sum += sets.at(i).second;
        }

        ll current = sum * sets.at(r).first;
        if (current < min) {
            min = current;
        }

        b2a.insert({sets.at(r).second, sets.at(r).first});
    }

    cout << "result" << endl;
    cout << min << endl;

}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}

