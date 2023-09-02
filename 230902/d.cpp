#include <bits/stdc++.h>

using namespace std;

unordered_map<long, int> memo;

int find_max(vector<vector<int>> & vals, long mask, int N) {
    if (memo.find(mask) != memo.end()) {
        return memo[mask];
    }

    if (N <= 1) {
        return 0;
    }
    if (N == 2) {
        int first_index = -1;
        int second_index = -1;
        for (int i = 0; i < vals.size(); i++) {
            if (mask >> i & 1) {
                continue;
            }
            if (first_index < 0) {
                first_index = i;
                continue;
            }
            second_index = i;
            break;
        }

        return vals.at(first_index).at(second_index);
    }
    int maximum = 0;
    int index = N - 1;
    for (int i = 0; i < vals.size(); i++) {
        if (mask >> i & 1) {
            continue;
        }
        int current = vals.at(i).at(index);
        long new_mask = mask;
        new_mask |= 1 << i;
        int next = find_max(vals, new_mask, N - 1);

        if (current + next > maximum) {
            maximum = current + next;
        }
    }

    return maximum;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> D(N);

    for (int i = 0; i < N; i++) {
        D.at(i).resize(N);
        for (int j = i; j < N-1; j++) {
            cin >> D.at(i).at(j);
        }
    }

    cout << find_max(D, 0, N) << endl;

}