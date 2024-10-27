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

    ll sum = 0;
    priority_queue<int> pq;
    for (int i = 0; i < K - 1; i++) {
        sum += sets.at(i).second;
        pq.push(sets.at(i).second);
    }

    ll min = __LONG_LONG_MAX__;

    for (int r = K-1; r < N; r++) {
        int next = sets[r].second;

        ll current = (sum + next) * sets.at(r).first;
        if (current < min) {
            min = current;
        }

        sum += next;
        pq.push(next);
        int out = pq.top();
        pq.pop();
        sum -= out;
    }

    cout << min << endl;

}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}

