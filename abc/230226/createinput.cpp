#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n = 50000;
    cout << 4 * n << endl;
    for (int i = 0; i < n; i++) {
        cout << 'R';
    }
    for (int i = 0; i < n; i++) {
        cout << 'D';
    }
    for (int i = 0; i < n; i++) {
        cout << 'L';
    }
    for (int i = 0; i < n; i++) {
        cout << 'U';
    }
}