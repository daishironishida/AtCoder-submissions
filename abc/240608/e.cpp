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

        //cout << "first: " << i << "," << index << endl;

        int next = a.at(i) - 1;
        bool revisit = false;
        while (visited.find(next) == visited.end()) {
            
            if (nums.find(next) != nums.end()) {
                revisit = true;
                break;
            }

            //cout << "next: " << next << "," << index << endl;

            // insert
            visited[next] = index;
            index++;
            order.push_back(next);

            next = a.at(next) - 1;
        }


        int cycle_size = index - visited[next];
        long sum;
        if (revisit) {
            sum = nums[next] + 1;
        } else {
            sum = pow(2, cycle_size - 1);
        }
        for (int j = visited[next]; j < index; j++) {
            nums[order.at(j)] = sum;
        }

        for (int j = visited[next] - 1; j >= 0; j--) {
            sum++;
            nums[order.at(j)] = sum;
        }
    }

    long sum = 0;
    for (pair<int, int> val : nums) {
        //cout << val.first << "," << val.second << endl;
        sum += val.second;
    }
    cout << sum;
}