// Tags: Amazon Heap Sort
// Time: O(n) on average
// Space: O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<tuple<double, int, int>> t;
        for (auto &p: points) {
            t.emplace_back(distance(p[0], p[1]), p[0], p[1]);
        }
        nth_element(t.begin(), t.begin() + K - 1, t.end());
        vector<vector<int>> res;
        for (int i = 0; i < K; ++i) {
            auto [d, x, y] = t[i];
            res.push_back({x, y});
        }
        return res;
    }
    double distance(int x, int y) {
        return pow(x, 2) + pow(y, 2);
    }
};




// Time: O(nlogK)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto dist = [](const vector<int> &v) {
            return v[0]*v[0] + v[1]*v[1];
        };

        partial_sort(points.begin(), points.begin() + K, points.end(), [&](const vector<int> &a, const vector<int> &b) {
            return dist(a) < dist(b);
        });
        // or nth_element(....., points.begin() + K - 1, ....., .....);

        return {points.cbegin(), points.cbegin() + K};
        // or vector<vector<int>>(points.begin(), points.begin() + K);
    }
};



// Time:  O(nlogk), online algorithm (adding data one by one)
// Space: O(k)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        const auto &dist = [](const vector<int> &v) {
            return v[0]*v[0] + v[1]*v[1];
        };

        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            return dist(a) < dist(b);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> max_heap(cmp);

        for (const auto &point: points) {
            max_heap.emplace(point);

            if (max_heap.size() > K) {
                max_heap.pop();
            }
        }

        vector<vector<int>> res;
        while (!max_heap.empty()) {
            res.emplace_back(max_heap.top()), max_heap.pop();
        }
        return res;
    }
};

/*
There is also an offline algorithm using min_heap. First we create heap (min heap) using
heapify, then we pop K elements.

priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(points.begin(), points.end(), cmp);

Time: O(n + klogn) ~ O(n)

Faster than online algorithm.
*/
