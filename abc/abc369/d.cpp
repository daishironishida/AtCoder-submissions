#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    long long optionA = a.at(0);
    long long optionB = 0;
    int count = 1;


    for (int i = 1; i < N; i++) {
        // optionA
        long long newOptionA = max(optionA, optionB + a.at(i));

        // optionB
        long long newOptionB = max(optionA + a.at(i) * 2, optionB);

        optionA = newOptionA;
        optionB = newOptionB;

    }

    cout << max(optionA, optionB);
}