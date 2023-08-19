#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> founds(26);

    
    int level = 1;
    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) == '(') {
            level++;
            continue;
        }
        if (S.at(i) == ')') {
            level--;
            for (int cindex = 0; cindex < 26; cindex++) {
                if (founds.at(cindex) >= level) {
                    founds.at(cindex) = 0;
                }
            }
            continue;
        }

        int index = S.at(i) - 'a';
        if (founds[index] > 0) {
            cout << "No" << endl;
            exit(0);
        }
        founds[index] = level;
    }
    cout << "Yes" << endl;
}