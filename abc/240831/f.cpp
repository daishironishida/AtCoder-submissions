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

    unordered_map<pair<int, int>, pair<int, string>, pair_hash> rewards;
    int value = map.at(0).at(0) ? 1 : 0;
    rewards[make_pair(0, 0)] = make_pair(value, "");

    for (int i = 1; i < H + W - 1; i++) {
        for (int r = 0; r < H; r++) {
            int c = i - r;
            if (c < 0 || c >= W) {
                continue;
            }

            int sum = 0;

            char direction;
            string str;
            if (r == 0) {
                direction = 'R';
                sum = rewards[make_pair(r, c-1)].first;
                str = rewards[make_pair(r, c-1)].second;
            } else if (c == 0) {
                direction = 'D';
                sum = rewards[make_pair(r-1, c)].first;
                str = rewards[make_pair(r-1, c)].second;
            } else {
                int rVal = rewards[make_pair(r-1, c)].first;
                int cVal = rewards[make_pair(r, c-1)].first;
                if (rVal > cVal) {
                    direction = 'D';
                    sum = rVal;
                    str = rewards[make_pair(r-1, c)].second;
                } else {
                    direction = 'R';
                    sum = cVal;
                    str = rewards[make_pair(r, c-1)].second;
                }
            }

            int current = map.at(r).at(c) ? 1 : 0;
            sum += current;
            str += direction;

            rewards[make_pair(r, c)] = make_pair(sum, str);
        }
    }

    cout << rewards[make_pair(H-1, W-1)].first << endl;
    cout << rewards[make_pair(H-1, W-1)].second << endl;

}