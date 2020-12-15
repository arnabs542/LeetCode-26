// Tags: Amazon D&C Binary-search
// Time: O(log(min(x,y))
// Space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //if input1 length is greater than switch them so that input1 is smaller than input2.
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int x = nums1.size(), y = nums2.size();
        int low = 0, high = x;
        int inf = 1e9;
        // Total elements on the left side = 
        // partx + party = (x + y + 1)/2;
        // (either no_of_elements(left side) == no_of_elements(right side)
        // or no_of_elements(left side) == no_of_elements(right side) + 1)
        while (low <= high) {
            // no of elements on the left side in case of nums1 
            // or start index for right side of nums1
            int partx = (low + high)/2;
            // no of elements on the left side in case of nums2
            // or start index for right side of nums2
            int party = (x + y + 1)/2 - partx;
            
            //if partx is 0 it means nothing is there on left side. Use -INF for maxleftx
            //if partx is length of input then there is nothing on right side. Use +INF for minrightx
            int maxleftx = (partx == 0) ? numeric_limits<int>::min() : nums1[partx - 1];
            int minrightx = (partx == x) ? numeric_limits<int>::max() : nums1[partx];
            
            int maxlefty = (party == 0) ? numeric_limits<int>::min() : nums2[party - 1];
            int minrighty = (party == y) ? numeric_limits<int>::max() : nums2[party];
            
            if (maxleftx <= minrighty && maxlefty <= minrightx) {
                // We have partitioned array at correct place
                // Now get max of left elements and min of right elements 
                // to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                return ((x + y) % 2 == 0) ? (max(maxleftx, maxlefty) + min(minrightx, minrighty)) / 2.0 :
                    max(maxleftx, maxlefty);
            } else if(maxleftx > minrighty) {
                //we are too far on right side for partx. Go on left side.
                high = partx - 1;
            } else {
                //we are too far on left side for partx. Go on right side.
                low = partx + 1;
            }
        }
        return -1;
        
    }
};

/*
Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
*/
