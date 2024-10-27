#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map.at(a-1).push_back(b-1);
    }

    deque<int> q;
    q.push_back(0);
    unordered_map<int, int> distance;
    distance[0] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop_front();

        for (int next : map.at(current)) {
            if (next == 0) {
                cout << distance[current] + 1 << endl;
                return 0;
            }
            if (distance.find(next) != distance.end()) {
                continue;
            }

            distance[next] = distance[current] + 1;
            q.push_back(next);
        }

    }
    cout << -1;

}