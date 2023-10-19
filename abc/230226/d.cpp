#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void count(unordered_map<int, int> &counts, int i, bool b, int val) {
    int hash = i + (int) b * (2 * 100000 + 1);
    counts[hash] = val;
};
int get_count(unordered_map<int, int> &counts, int i, bool b) {
    int hash = i + (int) b * (2 * 100000 + 1);
    return counts[hash];
};

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
        cin >> b.at(i);
    }

    unordered_map<int, int> counts;

    int divisor = 998244353;

    count(counts, 0, true, 1);
    count(counts, 0, false, 1);

    for (int i = 1; i < N; i++) {
        long long sum_true = 0;
        if (a[i] != a[i-1]) {
            sum_true += get_count(counts, i-1, true);
            sum_true = sum_true % divisor;
        }
        if (a[i] != b[i-1]) {
            sum_true += get_count(counts, i-1, false);
            sum_true = sum_true % divisor;
        }
        count(counts, i, true, sum_true);

        long long sum_false = 0;
        if (b[i] != a[i-1]) {
            sum_false += get_count(counts, i-1, true);
            sum_false = sum_false % divisor;
        }
        if (b[i] != b[i-1]) {
            sum_false += get_count(counts, i-1, false);
            sum_false = sum_false % divisor;
        }
        count(counts, i, false, sum_false);
    }
    
    long long result = 0;
    result += get_count(counts, N-1, true);
    result += get_count(counts, N-1, false);
    result = result % divisor;
    cout << result;
}