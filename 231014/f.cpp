#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u;
    int v;
    int b;
    int c;
};

struct Path {
    int current;
    long sum_b;
    long sum_c;
};

int main() {
    int N, M;
    cin >> N >> M;

    map<int, vector<Edge>> e;

    for (int i = 0; i < M; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        e[u].push_back({u, v, b, c});
    }


    map<int, vector<Path>> paths;
    paths[1] = vector<Path>();
    paths[1].push_back({1, 0, 0});

    for (int i = 1; i < N + 1; i++) {
        vector<Edge> &nexts = e[i];
        for (Edge &next : nexts) {
            for (Path current : paths[i]) {
                if (!paths.count(next.v)) {
                    paths[next.v] = vector<Path>();
                }

                paths[next.v].push_back({next.v, current.sum_b + next.b, current.sum_c + next.c});
            }
        }
    }

    // find best
    double best = 0;
    for (Path path : paths[N]) {
        best = max(best, (double)path.sum_b / path.sum_c);
    }

    cout << std::setprecision(15) << best << endl;
}