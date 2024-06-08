#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    
    int lowCount = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) >= 'a' && S.at(i) <= 'z') {
            lowCount++;
        }
    }

    for (int i = 0; i < S.size(); i++) {
        if (lowCount > S.size() - lowCount) {
            cout << (char)tolower(S.at(i));
        } else {
            cout << (char)toupper(S.at(i));
        }
    }

}