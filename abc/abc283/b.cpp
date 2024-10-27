#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        int k;
        cin >> type >> k;
        
        if (type == 1) {
            int x;
            cin >> x;
            a.at(k - 1) = x;
        } else {
            cout << a.at(k - 1) << endl;
        }
    }

}