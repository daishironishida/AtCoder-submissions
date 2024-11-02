#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<vector<int>> a(H);

    for (int i = 0; i < H; i++) {
        a.at(i) = vector<int>(W);
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                a.at(i).at(j) = 0;
            } else {
                a.at(i).at(j) = 1;
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // start from i,j

            struct hashFunction {
                size_t operator()(const pair<int , int> &x) const{
                    return x.first ^ x.second;
                }
            };
            class Path{
            public:
                unordered_set<pair<int, int>, hashFunction> path;
                pair<int, int> last;
                Path(pair<int, int> first) {
                    path = unordered_set<pair<int, int>, hashFunction>();
                    path.insert(first);
                    last = first;
                }

                void update(pair<int, int> next) {
                    path.insert(next);
                    last = next;
                }
            };

            deque<Path> q;
            q.emplace_back(make_pair(i, j));
            for (int k = 1; k < K; k++) {
                deque<Path> next_q;
                for (Path& path : q) {
                    pair<int, int> current = path.last;

                    vector<pair<int, int>> nexts;
                    nexts.push_back(make_pair(current.first + 1, current.second));
                    nexts.push_back(make_pair(current.first - 1, current.second));
                    nexts.push_back(make_pair(current.first, current.second + 1));
                    nexts.push_back(make_pair(current.first, current.second - 1));

                    for (auto& next : nexts) {
                        if (next.first >= H || next.first < 0 || next.second >= W || next.second < 0) {
                            continue;
                        }
                        if (a.at(next.first).at(next.second) == 1) {
                            continue;
                        }
                        if (path.path.count(make_pair(next.first, next.second)) != 0) {
                            continue;
                        }
                        Path nextPath = path;
                        path.update(next);
                        next_q.push_back(path);
                    }
                }
                q = next_q;
            }
            sum += q.size();
        }
    }

    cout << sum;

}