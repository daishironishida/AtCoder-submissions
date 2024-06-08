#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    unordered_map<int, int> nums;
    for (int i = 0; i < N; i++) {
        if (nums.find(i) != nums.end()) {
            continue;
        }

        int index = 0;
        unordered_map<int, long> visited;
        vector<int> order;
        order.reserve(10000);
        
        // insert
        visited[i] = index;
        index++;
        order.push_back(i);

        int next = a.at(i) - 1;
        bool revisit = false;
        while (visited.find(next) == visited.end()) {
            
            if (nums.find(next) != nums.end()) {
                revisit = true;
                break;
            }

            // insert
            visited[next] = index;
            index++;
            order.push_back(next);

            next = a.at(next) - 1;
        }


        int cycle_size = index - visited[next];
        long sum;
        if (revisit) {
            sum = nums[next];
        }  else {
            sum = pow(2, cycle_size);
            for (i = visited[next]; i < index; i++) {
                nums[order.at(i)] = sum;
            }

        }

        for (i = visited[next] - 1; i >= 0; i--) {
            sum++;
            nums[order.at(i)] = sum;
        }
    }

    long sum = 0;
    for (pair<int, int> val : nums) {
        sum += val.second;
    }
    cout << sum;
}