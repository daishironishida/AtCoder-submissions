#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int qCount = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            qCount++;
        }
    }

    long long count = 0;
    for (int i = 0; i < N-K+1; i++) {

        // count ?
        int thisQCount = 0;
        for (int j = 0; j < K-1; j++) {
            if (S[i+j] == '?') {
                thisQCount++;
            }
        }

        int thisCount = 0;
        bool notPalin = false;
        for (int j = 0; j < K/2; j++) {
            if (S[i+j] != S[i+K-j-1] && S[i+j] != '?' && S[i+K-j-1] != '?') {
                notPalin = true;
                break;
            }

            if (S[i+j] == '?') {

            }
        }

    }


}