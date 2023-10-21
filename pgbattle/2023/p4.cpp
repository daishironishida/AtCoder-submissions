#include <bits/stdc++.h>

using namespace std;


long long mult(long long a, long long b, long long divisor) {
    return (a * b) % divisor;
}

vector<unordered_multiset<int>> getSplits(int n) {
    vector<vector<int>> result;
    if (n % 3 == 0) {
        vector<int> threes(n/3, 3);
        result.push_back(threes);
    }
    vector<unordered_multiset<int>> prevs = getSplits(n-1);
    for (unordered_multiset<int> &prev : prevs) {
        if (prev.count(3) > 0) {

        }
    }
}

int main() {
    const long long three = 6 * 6;
    const long long four = 6 * 6 * 6 * 6;
    const long long five = 12 * 6 * 6 * 6 * 6 * 6;

    int N;
    cin >> N;

    long long M;
    cin >> M;


}