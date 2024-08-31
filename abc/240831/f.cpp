#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<bool>> map(H);

    for (int i = 0; i < H; i++) {
        map.at(i) = vector<bool>(W, false);
    }


    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        map.at(r-1).at(c-1) = true;
    }

    unordered_map<pair<int, int>, int, pair_hash> rewards;
    int value = map.at(0).at(0) ? 1 : 0;
    rewards[make_pair(0, 0)] = value;

    for (int i = 1; i < H + W - 1; i++) {
        for (int r = 0; r < H; r++) {
            int c = i - r;
            if (c < 0 || c >= W) {
                continue;
            }

            int sum = 0;
            if (r > 0) {
                sum = rewards[make_pair(r-1, c)];
            }
            if (c > 0) {
                sum = max(sum, rewards[make_pair(r, c-1)]);
            }

            int current = map.at(r).at(c) ? 1 : 0;
            sum += current;

            rewards[make_pair(r, c)] = sum;
        }
    }

    cout << rewards[make_pair(H-1, W-1)];

}