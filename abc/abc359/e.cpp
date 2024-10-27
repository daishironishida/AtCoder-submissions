#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    // height, index, total
    vector<tuple<long long, int, long long>> prevs;

    for (int i = 0; i < N; i++) {
        long long height;
        cin >> height;

        bool foundLargerPrev = false;
        int j;
        long long currentTotal;
        for (j = prevs.size()-1; j >= 0; j--) {
            if (get<0>(prevs[j]) > height) {
                foundLargerPrev = true;
                // 大きいの見つけた
                int diff = i - get<1>(prevs[j]);

                long long prevTotal = get<2>(prevs[j]);
                currentTotal = prevTotal + diff * height;
                cout << currentTotal << " ";
                break;
            }
        }

        if (foundLargerPrev) {
            prevs.resize(j+1);
            prevs.emplace_back(height, i, currentTotal);
            continue;
        }

        // 大きいのがない
        currentTotal = (i + 1) * height + 1;
        cout << currentTotal << " ";
        prevs.clear();
        prevs.emplace_back(height, i, currentTotal);
    }

}