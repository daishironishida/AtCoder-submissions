#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<long> a;

    for (int i = 0; i < N; i++) {
        long tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    vector<bool> deleted(N, false);
    for (int i = N-1; i >= 0; i--) {
        if (a.at(i) == 1) {
            int count = 0;
            for (int j = i; j < N; j++) {
                if (deleted.at(j)) {
                    continue;
                }
                if (a.at(j) == 1 + count) {
                    deleted.at(j) = true;
                    count++;
                } else {
                    break;
                }
            }
        }
    }

    long sum = 0;
    for (int i = 0; i < N; i++) {
        if (!deleted.at(i)) {
            sum += a.at(i);
        }
    }
    cout << sum << endl;

}