#include <bits/stdc++.h>

using namespace std;

bool check(string &s, string &t) {
    // equal
    if (s == t) {
        return true;
    }

    // add
    if (s.size() == t.size() + 1) {
        int added = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i + added] == t[i]) {
                continue;
            }
            if (added == 1) {
                return false;
            }
            added++;
            if (s[i + added] != t[i]) {
                return false;
            }
        }
        return true;
    }

    // remove
    if (s.size() == t.size() - 1) {
        int removed = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i + removed]) {
                continue;
            }
            if (removed == 1) {
                return false;
            }
            removed++;
            if (s[i] != t[i + removed]) {
                return false;
            }
        }
        return true;
    }

    if (s.size() != t.size()) {
        return false;
    }

    // changed
    bool changed = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t[i]) {
            continue;
        }
        if (changed) {
            return false;
        }
        changed = true;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    string t;
    cin >> t;

    vector<int> result;
    result.reserve(N);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (check(s, t)) {
            result.push_back(i + 1);
        }
    }
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
}