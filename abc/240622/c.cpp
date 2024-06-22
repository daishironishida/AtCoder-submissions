#include <bits/stdc++.h>

using namespace std;

int main() {
    long long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    bool isStartLeft = ((Sx % 2) + (Sy % 2)) % 2 == 0;

    long long vertical = abs(Sy - Ty);

    long long horizontal = abs(Sx - Tx);
    if ((isStartLeft && Tx > Sx) || (!isStartLeft && Tx < Sx)) {
        horizontal--;
    }


    long long horizontalMoves = horizontal - vertical;
    if (horizontalMoves <= 0) {
        cout << vertical;
        exit(0);
    }

    long long allMoves = vertical + (horizontalMoves + 1) / 2;
    cout << allMoves;






}