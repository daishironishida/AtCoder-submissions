#include <bits/stdc++.h>

using namespace std;


int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

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
        min += ctoi(s[N-i-1]) * pow(10, i);
    }

    // get max
    long max = 0;
    for (int i = 0; i < N; i++) {
        max += ctoi(s[i]) * pow(10, i);
    }

    // dict
    std::unordered_map<int, int> counts;
    for (int i = 0; i < N; i++) {
        counts[ctoi(s[i])]++;
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