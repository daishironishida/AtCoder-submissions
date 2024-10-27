#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> b(5 * N);

    for (int i = 0; i < 5 * N; i++) {
        cin >> b.at(i);
    }

    sort(b.begin(), b.end());

    float sum = 0;
    for (int i = N; i < 4 * N; i++) {
        sum += b[i];
    }
    float result = sum / (3 * N);
    cout << result;
}