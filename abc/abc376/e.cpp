#include <bits/stdc++.h>

using namespace std;

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

    // sort by second
    sort(sets.begin(), sets.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    priority_queue<pair<int, int>> pq;
    pair<int, int> pq_top;

    long long sum = 0;
    for (int i = 0; i < K; i++) {
        pq.push(sets.at(i));
        sum += sets.at(i).second;
    }
    pq_top = pq.top();
    pq.pop();
    sum *= pq_top.first;

    for (int i = K; i < N; i++) {
        //cout << "sum: " << sum << endl;
        pair<int, int> next_top = pq.top();

        long long minus = (pq_top.first - next_top.first) * (sum - pq_top.second) + pq_top.first + pq_top.second;
        long long plus;
        if (sets.at(i).first > next_top.first) {
            plus = (sets.at(i).first - next_top.first) * (sum - pq_top.second) + sets.at(i).first + sets.at(i).second;
        } else {
            plus = next_top.first * sets.at(i).second;
        }

        if (minus > plus) {
            sum = sum - minus + plus;
            if (sets.at(i).first > next_top.first) {
                pq_top = sets.at(i);
            } else {
                pq_top = next_top;
                pq.pop();
                pq.push(sets.at(i));
            }
        }

    }

    cout << sum << endl;

}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }
}

