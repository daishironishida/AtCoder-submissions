#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    deque<int> a;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    for (int i = N-1; i >= 0; i--) {
        if (a.at(i) == 1) {
            int count = 0;
            for (int j = i; j < N; j++) {
                if (a.at(j) == 1 + count) {
                    a.erase(a.begin() + j);
                    count++;
                } else {
                    break;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a.at(i);
    }
    cout << sum << endl;

}