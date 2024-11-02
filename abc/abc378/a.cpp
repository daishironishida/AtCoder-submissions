#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    map<int, int> a;

    for (int i = 0; i < 4; i++) {
        int input;
        cin >> input;
        if (a.find(input) == a.end()) {
            a[input] = 1;
        } else {
            a[input]++;
        }
    }

    int count = 0;
    for (auto itr = a.begin(); itr != a.end(); ++itr) {
        if (itr->second == 4) {
            cout << 2 << endl;
            return 0;
        }
        if (itr-> second >= 2) {
            count++;
        }
    }

    cout << count;

}