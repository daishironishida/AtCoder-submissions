#include <bits/stdc++.h>

using namespace std;

bool isInvalid(int base, int block, int target, bool increase) {
    if (increase) {
        if (target > base) {
            return (base < block) && (block < target);
        } else {
            return (base < block) || (block < target);
        }
    } else {
        if (target > base) {
            return (block < base) || (target < block);
        } else {
            return (target < block) && (block < base);
        }
    }
}

int minOps(int base, int block, int target, int N) {
    int ops = N;
    //cout << base << "," << block << "," << target << "," << N << endl;
    if (!isInvalid(base, block, target, true)) {
        //cout << "inc" << endl;
        if (target > base) {
            ops = min(ops, target - base);
        } else {
            ops = min(ops, target + N - base);
        }
    }
    if (!isInvalid(base, block, target, false)) {
        //cout << "dec" << endl;
        if (target > base) {
            ops = min(ops, base + N - target);
        } else {
            ops = min(ops, base - target);
        }
    }
    return ops;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<char> h(Q);
    vector<int> t(Q);

    for (int i = 0; i < Q; i++) {
        cin >> h.at(i);

        int value;
        cin >> value;
        t.at(i) = value - 1;
    }

    int l = 0;
    int r = 1;

    int sum = 0;
    for (int i = 0; i < Q; i++) {
        //cout << l << "," << r << "," << t.at(i) << endl;
        if (h.at(i) == 'L') {
            sum += minOps(l, r, t.at(i), N);
            l = t.at(i);
        } else if (h.at(i) == 'R') {
            sum += minOps(r, l, t.at(i), N);
            r = t.at(i);
        }
        //cout << sum << endl;
    }

    cout << sum;
}