//time O(n)
//space O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {


      if(prices.empty())
      return 0;

      int minPrice = numeric_limits<int>::max();
      int maxProfit = 0;

      for(const auto &p : prices){
        if(p < minPrice)
        minPrice = p;
        else if (p-minPrice > maxProfit)
        maxProfit = p - minPrice;
      }
        return maxProfit;
    }
};
