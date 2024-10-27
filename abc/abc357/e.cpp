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

        //cout << "first: " << i + 1 << "," << index << endl;

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

            //cout << "next: " << next + 1 << "," << index << endl;

            next = a.at(next) - 1;
        }


        int cycle_size = index - visited[next];
        int lastIndex;
        long sum;
        if (revisit) {
            sum = nums[next];
            lastIndex = index - 1;
        } else {
            sum = cycle_size;
            lastIndex = visited[next] - 1;
        }

        //cout << "finish: " << next + 1 << "," << index << "," << sum << endl;

        if (!revisit) {
            for (int j = visited[next]; j < index; j++) {
                nums[order.at(j)] = sum;
                //cout << "insert a: " << order.at(j) + 1 << "," << sum << endl;
            }
        }

        for (int j = lastIndex; j >= 0; j--) {
            sum++;
            nums[order.at(j)] = sum;
            //cout << "insert b: " << order.at(j) + 1 << "," << sum << endl;
        }
    }

    long sum = 0;
    for (pair<int, int> val : nums) {
        //cout << val.first + 1 << "," << val.second << endl;
        sum += val.second;
    }
    cout << sum;
}