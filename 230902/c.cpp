#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D, P;
    cin >> N >> D >> P;
    vector<long> F(N);

    for (long i = 0; i < N; i++) {
        cin >> F.at(i);
    }

    // sort F
    sort(F.begin(), F.end());

    // store cumulative sum
    for (long i = 1; i < N; i++) {
        F.at(i) += F.at(i - 1);
    }

    long minimum = LONG_MAX;
    long most_use_1day = (N / D) + 1;
    for (long i = 0; i <= most_use_1day; i++) {
        long total_cost = i * P;
        long num_ticket_days = N - i * D;
        if (num_ticket_days > 0) {
            total_cost += F.at(num_ticket_days-1);
        }

        if (total_cost < minimum) {
            minimum = total_cost;
        }
    }

    cout << minimum << endl;
}