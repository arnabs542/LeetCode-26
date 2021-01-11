// Tags: String Amazon Premium
// Time:  O(1)
// Space: O(1)
// Elegant solution
class Solution {
public:
    string nextClosestTime(string time) {
        // Like other solution, can also take vector
        // and do binary search, O(log4) ~ O(1)
        set<char> sorted;
        for (auto c : time) {
            if (c == ':')
                continue;
            sorted.insert(c);
        }
        string res {time};
        for (int i = 4; i >= 0; --i) {
            if (time[i] == ':')
                continue;
            // find in O(1)
            auto it = sorted.find(time[i]);
            if (it != prev(sorted.end())) {
                // if not the largest number
                // go to the next element
                ++it;
                res[i] = *it;
                if (i >= 3 && stoi(res.substr(3, 2)) < 60 || i < 2 && stoi(res.substr(0, 2)) < 24)
                    return res;
            }
            // else, take the smallest number
            res[i] = *sorted.begin();
        }
        return res;
    }
};
/*
Store the available digits (< 4) in set(sorted from minimum to maximum naturally);
Start from end of the time string, replace it with the next larger number in the set. 
    If available and a legal time (mm < 60 && hh <24), return the result;
Else replace it the smallest number in the set , go to the next digit in the time string.
*/



// Time:  O(1)
// Space: O(1)
class Solution {
public:
    string nextClosestTime(string time) {
        // no need to convert chars into ints
        // (as we can always compare chars)
        vector<char> digits {time[0], time[1], time[3], time[4]}; 
        sort(digits.begin(), digits.end());

        /* find the next bigger digit which is no more than limit. 
           If no such digit exists in digits[], return the minimum one
           i.e. digits[0]
        */
        auto findNext = [&] (char cur, char limit) {
            if (cur == limit)
                return digits[0];
            auto it = upper_bound(digits.begin(), digits.end(), cur);
            if (it == digits.end() || *it > limit)
                return digits[0];
            return *it;
        };
        string res{time};

        // find next digit for HH:M_, e.g. 23:43 -> 23:44
        res[4] = findNext(res[4], '9');
        if (res[4] > time[4])
            return res;

        // find next digit for HH:_M, e.g. 14:29 -> 14:41
        res[3] = findNext(res[3], '5');
        if (res[3] > time[3])
            return res;
        
        // find next digit for H_:MM, e.g. 02:37 -> 03:00
        res[1] = res[0] == '2' ? findNext(res[1], '3') : findNext(res[1], '9');
        if (res[1] > time[1])
            return res;
        
        // find next digit for _H:MM, e.g. 19:59 -> 11:11
        res[0] = findNext(res[0], '2');
        return res;
    }
};
