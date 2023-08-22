#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <utility>
#include <queue>
using namespace std;

int main() {
    int N , M;
    cin >> N >> M;
    vector<vector<int> > values(M);

    for (int i = 1; i <= N; i++) {
        int in;
        cin >> in;

        if (in > N) {
            continue;
        }
        int low = max((int)(-in / (float)i) + 1, 1);
        int high = min((int)((N-in) / (float)i), M);
        for (int j = low; j <= high; j++) {
            int next = in + i * j;
            if (next >= 0 && next <= N) {
                values[j-1].push_back(next);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        vector<bool> found(N+1, false);
        for (int val : values[i]) {
            found[val] = true;
        }
        int result = 0;
        while (found[result]) {
            result++;
        }
        cout << result << endl;
    }
}