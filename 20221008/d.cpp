#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <queue>
using namespace std;

bool is_valid(pair<int, int> pos, int N) {
    return pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < N;
}

int main() {
    int N , M;
    cin >> N >> M;

    set<pair<int, int> > valids;
    int i = 0;
    while (i * i <= M / 2.f) {
        int other = floor(sqrt(M - i * i));
        if (M == i * i + other * other) {
            valids.insert(make_pair(i, other));
            valids.insert(make_pair(-i, other));
            valids.insert(make_pair(i, -other));
            valids.insert(make_pair(-i, -other));
            valids.insert(make_pair(other, i));
            valids.insert(make_pair(-other, i));
            valids.insert(make_pair(other, -i));
            valids.insert(make_pair(-other, -i));
        }
        i += 1;
    }

    vector<vector<int> > grid(N);
    for (int i = 0; i < N; i++) {
        grid[i] = vector<int>(N, -1);
    }
    grid[0][0] = 0;

    vector<pair<int, int> > q;
    q.push_back(make_pair<int, int>(0, 0));
    while (!q.empty()) {
        vector<pair<int, int> > next_q;
        for (auto &pos : q) {
            for (auto &valid : valids) {
                pair<int, int> next_pos(pos.first + valid.first, pos.second + valid.second);

                if (!is_valid(next_pos, N)) {
                    continue;
                }
                if (grid[next_pos.first][next_pos.second] >= 0) {
                    continue;
                }
                grid[next_pos.first][next_pos.second] = grid[pos.first][pos.second] + 1;
                next_q.push_back(next_pos);
            }
        }
        q = next_q;
    }

    for (auto &row : grid) {
        for (auto val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }
}

