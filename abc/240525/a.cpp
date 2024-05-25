#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    bool one = false;
    bool two = false;
    bool three = false;

    if (a == 1 || b == 1) {
        one = true;
    }
    if (a == 2 || b == 2) {
        two = true;
    }
    if (a == 3 || b == 3) {
        three = true;
    }

    if (one && two) {
        cout << "3";
    } else if (two && three) {
        cout << "1";
    } else if (one && three) {
        cout << "2";
    } else {
        cout << "-1";
    }

}