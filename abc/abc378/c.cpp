#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    unordered_map<ll, int> map;

    for (int i = 0; i < N; i++) {
        ll input;
        cin >> input;
        if (map.find(input) == map.end()) {
            cout << -1 << " ";
        } else {
            cout << map[input] << " ";
        }
        map[input] = i + 1;
    }

}