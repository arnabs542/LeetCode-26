// Tags: Heap Greedy WC221
// Time: O(nlogn)
// Space: O(n)
// Heap solution
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // expiry data, count
        using T = pair<int, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        int res = 0;
        int i = 0;
        while (i < apples.size() || !min_heap.empty()) {
            if (i < apples.size())
                min_heap.push({i + days[i], apples[i]});
            while (!min_heap.empty() && min_heap.top().first <= i)
                min_heap.pop();
            if (!min_heap.empty()) {
                auto a = min_heap.top(); min_heap.pop();
                --a.second;
                ++res;
                if (a.second > 0)
                    min_heap.push(a);
            }
            ++i;
        }
        return res;
    }
};



// Wrong answer, passed only few test cases
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // count, expiry date
        queue<pair<int, int>> q;
        int res = 0;
        int i = 0;
        while (i < apples.size() || !q.empty()) {
            if (i < apples.size())
                q.push({apples[i], i + days[i]});
            while (!q.empty() && q.front().second <= i)
                q.pop();
            if (!q.empty()) {
                --q.front().first;
                ++res;
                if (q.front().first == 0)
                    q.pop();
            }
            ++i;
        }
        return res;
    }
};

/*
Normal queue gives wrong answer because in order to have maximum
apples we have to consume those apples first which expiry early (and they
don't necessarily be the ones which are pushed early.)

Therefore we use min head instead.
*/
