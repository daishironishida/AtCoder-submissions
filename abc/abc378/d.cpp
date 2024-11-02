#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

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
            if (a.at(i).at(j) == 1) {
                continue;
            }

            // start from i,j

            class Path{
            public:
                unordered_set<pair<int, int>, pairhash> path;
                pair<int, int> last;
                Path(pair<int, int> first) {
                    path = unordered_set<pair<int, int>, pairhash>();
                    path.insert(first);
                    last = first;
                }

                void update(pair<int, int> next) {
                    path.insert(next);
                    last = next;
                }
            };

            vector<shared_ptr<Path>> q;
            q.push_back(make_shared<Path>(make_pair(i, j)));
            for (int k = 0; k < K; k++) {
                vector<shared_ptr<Path>> next_q;
                next_q.reserve(q.size() * 4);
                
                //cout << "loop:" << k << endl;
                for (shared_ptr<Path> path : q) {
                    pair<int, int> current = path->last;


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
                        if (path->path.count(next) != 0) {
                            continue;
                        }

                        /*
                        cout << "path: ";
                        for (auto& p : path.path) {
                            cout << p.first << "," << p.second << " ";
                        }
                        cout << "append: " << next.first << "," << next.second << endl;
                        */

                        Path nextPath = *path;
                        nextPath.update(next);
                        next_q.push_back(make_shared<Path>(nextPath));
                    }
                }
                q = std::move(next_q);
            }
            //cout << i << "," << j << ": " << q.size() <<endl;
            sum += q.size();
        }
    }

    cout << sum;

}