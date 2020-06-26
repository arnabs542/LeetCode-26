// Time O(n)
// Space O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j = height.size()-1 , max_area = 0;

        while (i < j){
          max_area = max(max_area, min(height[i], height[j]) * (j-i) );
          if (height[i] < height[j]){
            i++;
          }else if (height[i] > height[j]){
            j--;
          } else {
            i++, j--;
          }
        }
        return max_area;
    }

};

// Notes:
// If we found an area with height h, the only choice that could beat this
// if when new height is > h because the width would keep on decreasing.
