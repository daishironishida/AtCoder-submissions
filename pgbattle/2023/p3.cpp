#include <bits/stdc++.h>

using namespace std;

long long mult(long long a, long long b) {
    long long divisor = 998244353;
    return (a * b) % divisor;
}

unordered_map<int, long long> factorials;

long long factorial(int n) {
    if (factorials.count(n) > 0) {
        return factorials[n];
    }
    if (n == 0) {
        factorials[0] = 1;
        return 1;
    }
    long long result = factorial(n-1) * n;
    factorials[n] = result;
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    int numLoops = gcd(N, K); 
    int numValues = N / numLoops;

    long long base = factorial(numValues);


    long long result = 1;
    for (int l = 0; l < numLoops; l++) {
        unordered_map<int, int> counts;
        for (int i = 0; i < numValues; i++) {
            int value = a.at(i * numLoops + l);
            if (counts.count(value) == 0) {
                counts[value] = 1;
            } else {
                counts[value]++;
            }
        }

        long long product = base;

        for (auto pair : counts) {
            product = product / factorial(pair.second);
        }

        result = mult(result, product);
    }

    cout << result;


}