#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    list<int> a;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    
    for (auto itr = a.rbegin(); itr != a.rend(); itr++) {
        if (*itr == 1) {
            int count = 0;
            for (auto itr2 = itr.base(); itr2 != a.end(); itr2++) {
                if (*itr2 == 1 + count) {
                    itr2 = a.erase(itr2);
                    count++;
                } else {
                    break;
                }
            }
        }
    }

    int sum = 0;
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        sum += *itr;
    }
    cout << sum << endl;

}