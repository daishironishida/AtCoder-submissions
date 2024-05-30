#include <bits/stdc++.h>

using namespace std;


class Node {
    pair<int, int> location;
    shared_ptr<Node> leftChild;
    shared_ptr<Node> rightChild;

public:
    Node(vector<pair<int, int>> &points, int start, int end, int depth) {
        int axis = depth % 2;

        // sort by axis gcc
        sort(points.begin() + start, points.begin() + end, [axis](pair<int, int> a, pair<int, int> b) {
            if (axis == 0) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
        });

        int median = points.size() / 2;
        location = points[median];
        leftChild = make_shared<Node>(points, 0, median, depth + 1);
        rightChild = make_shared<Node>(points, median, points.size(), depth + 1);
    }

    int count_range(int x_max, int y_min, int depth) {
        int axis = depth % 2;

        int value = axis == 0 ? location.first : location.second;
        
        if (axis == 0) {
            if (value > x_max) {
                return leftChild->count_range(x_max, y_min, depth + 1);
            }
            return leftChild->count_range(x_max, y_min, depth + 1) + rightChild->count_range(x_max, y_min, depth + 1) + 1;
        } else {
            if (value < y_min) {
                return rightChild->count_range(x_max, y_min, depth + 1);
            }
            return leftChild->count_range(x_max, y_min, depth + 1) + rightChild->count_range(x_max, y_min, depth + 1) + 1;
        }
    }
};

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> a(N);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        a.at(i) = make_pair(x, y);
    }

    Node root(a, 0, N, 0);

    int sum = 0;
    for (auto p : a) {
        sum += root.count_range(p.second, p.first, 0);
    }

    cout << (sum - N) / 2;

}