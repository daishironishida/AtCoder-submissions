#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int thresh = (N + 1) / 2;
    int count = 0;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "For") {
            count++;
            if (count >= thresh) {
                cout << "Yes";
                break;
            }
        }
    }
    if (count < thresh) {
        cout << "No";
    }
}