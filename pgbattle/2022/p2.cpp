#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> a(3 * N);

    for (int i = 0; i < 3 * N; i++) {
        cin >> a.at(i).first;
        a.at(i).second = i + 1;
    }

    // sort by first element
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    
    set<int> result;
    for (int i = N; i < 2 * N; i++) {
        result.insert(a.at(i).second);
    }

    for (int res : result) {
        cout << res << endl;
    }
}