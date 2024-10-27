#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "Takahashi") {
            count++;
        }
    }
    cout << count;

}