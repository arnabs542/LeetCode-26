// Tags: Sort Google
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // position, time to reach the target
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); ++i) {
            cars.emplace_back(position[i], static_cast<double>(target - position[i])/speed[i]);
        }
        sort(cars.begin(), cars.end());
        // number of fleets
        int res = 0;
        // current time needed by slowest(lead) car
        double cur = 0;
        for (int i = cars.size() - 1; i >= 0; --i) {
            if (cars[i].second > cur) {
                ++res;
                cur = cars[i].second;
            }
        }
        return res;
    }
};
/*
* Sort cars by the start positions
* Loop on each car from the end to the beginning
* Calculate its time needed to arrive the target

cur records the current biggest time (the slowest, by the 'lead')

If next car needs less or equal time than cur,
it can catch up this car fleet (and join with it).

If next car needs more time, it will be the new slowest car,
and becomes the new 'lead' of a new car fleet.
*/
