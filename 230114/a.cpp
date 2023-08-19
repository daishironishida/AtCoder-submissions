#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int a;
    cin >> a;
    a -= 1;

    int divisor = 100000;
    int s1 = a / divisor + 1;
    a = a % divisor;
    divisor = divisor / 10;

    int s3 = a / divisor;
    a = a % divisor;
    divisor = divisor / 10;

    int s4 = a / divisor;
    a = a % divisor;
    divisor = divisor / 10;

    int s5 = a / divisor;
    a = a % divisor;
    divisor = divisor / 10;

    int s7 = a / divisor;
    a = a % divisor;
    divisor = divisor / 10;

    int s8 = a;

    //cout << s1 << s3 << s4 << s5 << s7 << s8 << endl;


    int result = s7;
    int mult = 10;

    result += s8 * mult;
    mult *= 10;

    result += s7 * mult;
    mult *= 10;

    result += s5 * mult;
    mult *= 10;

    result += s5 * mult;
    mult *= 10;

    result += s4 * mult;
    mult *= 10;

    result += s3 * mult;
    mult *= 10;

    result += s1 * mult;
    mult *= 10;

    result += s1 * mult;
    mult *= 10;

    cout << result;
}