#include <bits/stdc++.h>

using namespace std;

bool isValid(char query, char truth) {
    return query == '?' || query == truth;
}

double eval(string& s, int index) {
    if (!isValid(s[index], 'A')) {
        return 0;
    }
    if (!isValid(s[index+1], 'B')) {
        return 0;
    }
    if (!isValid(s[index+2], 'C')) {
        return 0;
    }

    int q_count = 0;
    for (int i = index; i < min(index + 3, (int)s.size()); i++) {
        if (s[i] == '?') {
            q_count++;
        }
    }
    return pow(3, -q_count);
}

int main() {
    string s;
    cin >> s;

    double sum = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        sum += eval(s, i);
    }

    cout << setprecision(10) << sum;
}