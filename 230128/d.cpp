#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int N = T.size();
    int M = S.size();
    
    vector<bool> isInvalid(N+1);

    int i = 0;
    // 先頭のチェック。ここでマッチしなければindex greater than iは全てNG
    while (i < N) {
        char sChar = S.at(i);
        char tChar = T.at(i);
        i++;
        if (sChar == '?') {
            continue;
        }
        if (tChar == '?') {
            continue;
        }
        if (sChar == tChar) {
            continue;
        }

        while (i <= N) {
            isInvalid.at(i) = true;
            i++;
        }
    }

    // 末尾のチェック。ここでマッチしなければindex less than or equal to jは全てNG 
    int j = 1;

    while (j <= N) {
        char sChar = S.at(M-j);
        char tChar = T.at(N-j);
        if (sChar == '?') {
            j++;
            continue;
        }
        if (tChar == '?') {
            j++;
            continue;
        }
        if (sChar == tChar) {
            j++;
            continue;
        }

        while (j <= N) {
            isInvalid.at(N-j) = true;
            j++;
        }
    }

    for (int k = 0; k < N+1; k++) {
        if (isInvalid.at(k)) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}