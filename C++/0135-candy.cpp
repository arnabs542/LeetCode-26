// Tags: Greedy Amazon
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        // Give each child 1 candy
        vector<int> candies(ratings.size(), 1);
        
        // Scan from left to right, to make sure right higher rated
        // child gets 1 more candy than 'left' lower rated child
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        
        // Scan from right to left, to make sure left higher rated child gets 1 more candy than 'right' lower rated child
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
            // if (ratings[i] > ratings[i + 1])
            //   max(candies[i], candies[i + 1] + 1)
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

/*
The rating is similar to 'wave', increase of decrease

let's look at this case:
ratings: [1,3,6,9,4,2]
candies: [1,2,3,4,2,1]

The highest rating is 9, when scan from left to right, 
num of candies should be 4, scan right to left, it should be 3, 
then we choose the larger value.
*/
