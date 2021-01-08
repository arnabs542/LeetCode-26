// Time:  O(nlogn)
// Space: O(n)
// Binary-search solution, maintaining active list 
// (Similar to Insertion sort)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS;

        for (const auto &num : nums)
            insert(LIS, num);

        return LIS.size();
    }

private:
    void insert(vector<int> &LIS, const int target)
    {
        int left = 0, right = LIS.size() - 1;
        auto comp = [] (int x, int target) {return x >= target;};

    // find the first index (leftmost) "left" which satisfies LIS[mid] >= target
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (comp(LIS[mid], target))
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left == LIS.size())
            LIS.emplace_back(target);
        else
            LIS[left] = target;
    }
};



// Better solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (auto n: nums) {
            int left = 0, right = tails.size() - 1;
            int ans = tails.size();
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (tails[mid] >= n){
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (ans == tails.size())
                tails.push_back(n);
            else
                tails[ans] = n;
        }
        return tails.size();
    }
};

/*
We are keeping track of active/latest list. LIS[i] gives us the last elem of last subsequence of size i + 1.
Since we are only keeping track of the latest list, LIS will be sorted and therefore we use binary search
to find the leftmost elem satisfying 'tails[mid] >= n' which gives us the index of the element to be replaced
i.e. ans.

Here we are using just a list instead of list of lists, therefore we can't find the actual subsequence.

Algorithm to find actual subsequences of each length:
1. If A[i] is the smallest among all end candidates of active lists, start a new active list with A[i] of length 1.
2. If A[i] is largest among all end candidates of active lists, clone the largest active list, and append A[i] to it.
3. If A[i] is in between, find the list with the largest end number that is smaller than A[i]. Clone and append A[i] to this list.
4. Discard all other lists of the same length as that of this modified list.
*/



// Same as above but using lower_bound for binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (const auto &n: nums) {
            auto it = lower_bound(tails.begin(), tails.end(), n);

            if (it == tails.end())
                tails.push_back(n);
            else
                *it = n;
        }
        return tails.size();
    }
};



// Time:  O(n^2)
// Space: O(n)
// Traditional DP solution.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};
