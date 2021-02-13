// Tags: Greedy Sort Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {\
        // sort by number of units (decreasing order)
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
            return a[1] > b[1];
        });
        int res = 0;
        for (const auto& boxType : boxTypes) {
            if (truckSize > boxType[0]) {
                // available truckSize > total number of boxes of this type
                // (still have to go to the next boxType, so put all boxes)
                truckSize -= boxType[0];
                res += boxType[0]*boxType[1];
            } else {
                // available truckSize <= boxType[0]
                // (last type to be put, put only truckSize boxes)
                res += truckSize*boxType[1];
                break;
            }
        }
        return res;
    }
};
