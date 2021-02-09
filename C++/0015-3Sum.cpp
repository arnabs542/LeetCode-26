// Tags: Array Two-pointers Amazon
// Time O(n^2)
// Space O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if(nums.size() <= 2) {
            return output;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < static_cast<int>(nums.size()) - 2; i++) {
            // or we can skip checking these conditions here and put a
            // while loop below as shown
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i + 1;
                int high = nums.size() - 1;
                int sum = 0 - nums[i];
                while(low < high){
                    if (nums[low] + nums[high] == sum){
                        output.push_back({nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low+1])
                            low++;
                        while (low < high && nums[high] == nums[high-1])
                            high--;
                        low++;
                        high--;
                } else if (nums[low] + nums[high] > sum){
                        high--;
                    } else {
                        low++;
                    }
                }
            }
            // while (i < nums.size() - 2 && nums[i + 1] == nums[i])
            //  ++i;
        }
        return output;
    }
};

/*
 If I fix two elements, there will only be one possible choice for third one.
 Here sorting is done so that we can avoid duplicate elements
*/
