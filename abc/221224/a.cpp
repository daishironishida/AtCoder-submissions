#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    long long a;
    long long b;
    cin >> a >> b;
    long long result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    cout << result << endl;
}