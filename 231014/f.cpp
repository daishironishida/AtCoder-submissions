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


    map<int, Path> paths;
    paths[1] = {1, 0, 0};

    for (int i = 1; i < N + 1; i++) {
        Path current = paths[i];
        vector<Edge> &nexts = e[i];
        for (Edge &next : nexts) {
            float next_ratio = float(current.sum_b + next.b) / (current.sum_c + next.c);

            if (paths.count(next.v)) {
                Path &best = paths[next.v];
                if (best.sum_b / best.sum_c < next_ratio) {
                    paths[next.v] = {next.v, current.sum_b + next.b, current.sum_c + next.c};
                }
            } else {
                paths[next.v] = {next.v, current.sum_b + next.b, current.sum_c + next.c};
            }
        }
    }

    cout << std::setprecision(15) << (double)paths[N].sum_b / paths[N].sum_c;

}