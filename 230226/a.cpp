#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0;
    while (i < s.size()) {
        if (isupper(s[i])) {
            break;
        }
        i++;
    }
    cout << i+1;
}