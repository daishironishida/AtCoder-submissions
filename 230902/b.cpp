#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    array<array<int, 100>, 100> has;

    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            has.at(j).at(k) = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < b; j++) {
            for (int k = c; k < d; k++) {
                has.at(j).at(k)++;
            }
        }
    }

    int result = 0;
    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (has.at(j).at(k) > 0) {
                result++;
            }
        }
    }

    cout << result << endl;

}