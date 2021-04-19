// Tags: Math Stack Google
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> st, res(cars.size(), -1);
        auto col_time = [&](int l, int r) {
          return (double)(-cars[l][0] + cars[r][0])/(cars[l][1] - cars[r][1]);  
        };
        for (int i = cars.size() - 1; i >= 0; --i) {
            while (!st.empty() && (cars[i][1] <= cars[st.back()][1] || st.size() > 1 && col_time(i, st.back()) >= res[st.back()])) {
                st.pop_back();
            }
            res[i] = st.empty() ? -1 : col_time(i, st.back());
            st.push_back(i);
        }
        return res;
    }
};
/*
Intuition:
- Go from right to left, and only consider cars up ahead.
- If someone bumps into us, our speed won't change but that car will attain our speed.
- If car3 collides with car2 before car2 collides with car1, relatively car3 collides with car2
  However if car3 collides with car2 after car2 collided with car1, relatively car3 collides
  with car1.

Solution:
Process cars from right to left and maintain a stack of cars with monotonically increasing
speeds.
1. If current car is slower than the slowest car up ahead, it won't collide and stack needs
   to be emptied.
2. Now if there are cars left in the stack, the current car surely would collide.
   Also, all cars in the stack - except the first/bottom most one - have collided with some
   other car at some point.
3. So, we go from top (fastest car) of the stack and check
    - If we collide with it after it collided with cars up ahead, we can ignore that car and
      remove it from the stack.
4. Calculate the collision time relative to the topmost car in the stack

For calculating collision time, we take (relative distance)/(relative speed).
*/
