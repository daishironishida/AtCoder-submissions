#include <bits/stdc++.h>

using namespace std;

double eval(string& s, int index, int q_count) {
    if (s[index] != 'A' && s[index] != '?') {
        return 0;
    }
    if (s[index+1] != 'B' && s[index+1] != '?') {
        return 0;
    }
    if (s[index+2] != 'C' && s[index+2] != '?') {
        return 0;
    }

    int q_other = q_count;
    for (int i = index; i < min(index + 3, (int)s.size()); i++) {
        if (s[i] == '?') {
            q_other--;
        }
    }
    return pow(3, q_other - q_count);
}

int main() {
    string s;
    cin >> s;

    int q_count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            q_count++;
        }
    }

    double sum = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        sum += eval(s, i, q_count);
    }

    cout << setprecision(10) << sum;
}