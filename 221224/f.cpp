#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);

    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        int diff = 1;
        int min = 2 * N;
        while (diff < min - 1) {
            // less
            if (i - diff >= 0) {
                int current = diff + abs(p.at(i) - p.at(i - diff));
                //cout << "less" << i << "," << current << "," << diff << endl;
                if (current < min) {
                    min = current;
                }
            }

            // more
            if (i + diff < N) {
                int current = diff + abs(p.at(i) - p.at(i + diff));
                //cout << "more" <<  i << "," << current << "," << diff << endl;
                if (current < min) {
                    min = current;
                }
            }

            // next loop
            diff++;
        }
        result.at(i) = min;
    }
    cout << result.at(0);
    for (int i = 1; i < N; i++) {
        cout << " " << result.at(i);
    }
    cout << endl;
}