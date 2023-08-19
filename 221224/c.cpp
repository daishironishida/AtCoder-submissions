#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    
    int count = 0;
    int i = 0;
    while (i < N) {
        if (S.at(i) != '0') {
            count++;
            i++;
            continue;
        }
        if (i + 1 >= N) {
            count++;
            break;
        }
        if (S.at(i+1) != '0') {
            count += 2;
            i += 2;
            continue;
        }
        count += 1;
        i += 2;
    }
    cout << count << endl;

}