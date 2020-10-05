// Time:  O(nlogn)
// Space: O(n)
// Binary search solution
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

    // find the first index "left" which satisfies LIS[left] >= target
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

/*
Notes:
At the end of loop, left give us the position of rightmost element (largest length)
satifying condition ie. !comp and right moves to one position behind left.
Here we are using just a list instead of list of lists, therefore we can't
find the actual subsequence. (LIS[i] gives us the last elem of subsequence
of size i + 1)

We are keeping track of active/latest lists of different sizes.
LIS[i] gives us the last elem of subsequence of size i + 1.
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (auto n: nums) {
            int left = 0, right = tails.size() - 1;
            int ans = left;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (tails[mid] >= n){
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
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