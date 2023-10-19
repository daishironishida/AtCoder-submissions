#include <bits/stdc++.h>

using namespace std;

int calc_pascal_sum(vector<int> & nums) {
    int result = 0;
    for (int j = 1; j <= nums.size(); j++) {
        for (int k = 0; k < nums.size() - j + 1; k++) {
            for (int i = 0; i < j; i++) {
                result += nums.at(k + i);
            }
        }
    }
    return result;
}

int calc_sandwiches(vector<int> & indices) {
    if (indices.size() <= 1) {
        return 0;
    }

    vector<int> diffs;
    for (int i = 0; i < indices.size() - 1; i++) {
        diffs.push_back(indices.at(i + 1) - indices.at(i) - 1);
    }

    return calc_pascal_sum(diffs);
}

int main() {
    int N;
    cin >> N;
    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        indices[val].push_back(i);
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> this_indices = indices[i];

        result += calc_sandwiches(this_indices);
    }

    cout << result << endl;

}