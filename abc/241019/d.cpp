#include <bits/stdc++.h>

using namespace std;

class Path {
public:
    Path() {
        current = 0;
        visited.insert(0);
    }
    Path(int start) {
        current = start;
        visited.insert(start);
    }
    unordered_set<int> visited;
    int current;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map.at(a-1).push_back(b-1);
    }

    deque<Path> q;
    Path start(0);
    q.push_back(start);
    unordered_map<int, Path> visited;
    visited[0] = start;

    while (!q.empty()) {
        Path current = q.front();
        q.pop_front();

        for (int next : map.at(current.current)) {
            /*
            cout << "visit: " << current.current << "," << next << ", visited: ";
            for (int v : current.visited) {
                cout << v << ",";
            }
            cout << endl;
            */

            if (visited.find(next) != visited.end()) {
                cout << current.visited.size() + visited[next].visited.size() - 1 << endl;
                return 0;
            }

            if (current.visited.find(next) != current.visited.end()) {
                continue;
            }
            Path nextPath = current;
            nextPath.visited.insert(next);
            nextPath.current = next;
            q.push_back(nextPath);
            visited[current.current] = current;
        }
    }
    cout << -1;

}