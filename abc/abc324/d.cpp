#include <bits/stdc++.h>

using namespace std;

bool checkPerm(long a, unordered_map<int, int> counts, int n) {
    for (int i = 0; i < n; i++) {
        int digit = a % 10;
        if (counts[digit] == 0) {
            return false;
        }
        counts[digit]--;
        a /= 10;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    
    // get min
    long min = 0;
    for (int i = 0; i < N; i++) {
        min += int(s[N-i-1] - '0') * pow(10, i);
    }

    // get max
    long max = 0;
    for (int i = 0; i < N; i++) {
        max += int(s[i] - '0') * pow(10, i);
    }

    // dict
    std::unordered_map<int, int> counts;
    for (int i = 0; i < N; i++) {
        counts[int(s[i]) - '0']++;
    }

    // sqmin/max
    long sqmin = sqrt(min);
    long sqmax = sqrt(max);

    // debug
    /*
    cout << min << " " << max << endl;
    cout << sqmin << " " << sqmax << endl;
    */

    // loop
    int count = 0;
    for (long i = sqmin; i <= sqmax; i++) {
        long val = i * i;
        if (checkPerm(val, counts, N)) {
            count++;
        }
    }
    cout << count;
}