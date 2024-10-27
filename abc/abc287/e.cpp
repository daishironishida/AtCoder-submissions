#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int lcp(set<string>::iterator a, set<string>::iterator b) {
    int minLength = min(a->size(), b->size());
    for (int i = 0; i < minLength; i++) {
        if (a->at(i) != b->at(i)) {
            return i;
        }
    }
    return minLength;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    multiset<string> ordered;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.at(i) = s;
        ordered.insert(s);
    }

    for (int i = 0; i < N; i++) {
        int maxVal = 0;

        auto current = ordered.find(S.at(i));
        if (current != ordered.begin()) {
            maxVal = lcp(current, prev(current));
        }
        auto nextItr = next(current);
        if (nextItr != ordered.end()) {
            int val = lcp(current, nextItr);
            maxVal = max(maxVal, val);
        }
        cout << maxVal << endl;
    }
}