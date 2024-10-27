#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    if (N == 1) {
        cout << 1;
        exit(0);
    }

    long long result = N + (N - 1);

    long long prevDiff = a.at(1) - a.at(0);
    long long sameDiffCount = 1;
    for (int i = 2; i < N; i++) {
        long long diff = a.at(i) - a.at(i-1);
        if (diff == prevDiff) {
            sameDiffCount++;
        } else {
            result += sameDiffCount * (sameDiffCount - 1) / 2;
            prevDiff = diff;
            sameDiffCount = 1;
        }
    }
    if (sameDiffCount > 1) {
        result += sameDiffCount * (sameDiffCount - 1) / 2;
    }
    cout << result;
}