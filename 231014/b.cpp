#include <bits/stdc++.h>

using namespace std;

int isPower(long long x) {
    if (x == 1) {
        return true;
    }
    if (x % 2 != 0 && x % 3 != 0) {
        cout << "No";
        exit(0);
    }
    if (x % 2 != 0) {
        return isPower(x / 3);
    }
    return isPower(x / 2);
}

int main() {
    long long N;
    cin >> N;

    if (isPower(N)) {
        cout << "Yes";
        exit(0);
    }
    cout << "No";
}