#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<char> s(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        cin >> s.at(i);
    }

    int prevL = -1;
    int prevR = -1;

    int cost = 0;
    for (int i = 0; i < N; i++) {
        if (s.at(i) == 'L') {
            if (prevL < 0) {
                prevL = a.at(i);
                continue;
            }
            cost += abs(prevL - a.at(i));
            prevL = a.at(i);
        } else {
            if (prevR < 0) {
                prevR = a.at(i);
                continue;
            }
            cost += abs(prevR - a.at(i));
            prevR = a.at(i);
        }
    }

    cout << cost;

}