#include <bits/stdc++.h>

using namespace std;

const long DIVISOR = 998244353;
const long REMAINDER = 1755647;

long add(int digit, long &currentRemainder, long &lastRemainder) {
    lastRemainder *= 10;
    lastRemainder = lastRemainder % DIVISOR;

    currentRemainder += digit * lastRemainder;
    currentRemainder = currentRemainder % DIVISOR;
}

int main() {
    string N;

    string input = "100000000";

    long result = 0;
    long lastRemainder = 0;
    for (int i = input.size() - 1; i >= 0; i--) {
        add(input[i] - '0', result, lastRemainder);
    }


}