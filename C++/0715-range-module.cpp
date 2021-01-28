// Tags: Segment-tree Ordered-map Amazon
// Time:  addRange:    O(n)
//        removeRange: O(n)
//        queryRange:  O(logn)
// Space: O(n)
class RangeModule {
private:
    vector<pair<int, int>> invals;
public:
    RangeModule() {
        
    }
    
    // like merge intervals
    // (find correct place for the interval
    // to be put. Also keep merging i.e. creating a bigger
    // interval if it overlaps with some interval)
    // Eg. [10 20) [22 30) add (15 25) -> [10 30)
    void addRange(int left, int right) {
        int n = invals.size();
        // new invals
        vector<pair<int, int>> tmp;
        for (int i = 0; i <= n; ++i) {
            if (i == n || invals[i].first > right) {
                // i == n or found first non-overlapping invals[i]
                // with start > right
                // put this interval [left right) here
                tmp.push_back({left, right});
                while (i < n)
                    tmp.push_back(invals[i++]);
            } else if (invals[i].second < left) {
                // non-overlapping invals[i] with end < left
                tmp.push_back(invals[i]);
            } else {
                // overlapping interval invals[i] in either of two ways
                // update [left right)
                left = min(left, invals[i].first);
                right = max(right, invals[i].second);
            }
        }
        swap(invals, tmp);
    }
    
    bool queryRange(int left, int right) {
        int l = 0, r = invals.size() - 1;
        while (l <= r) {
            int m = l + (r - l)/2;
            if (invals[m].first > right)
                r = m - 1; // non-overlapping
            else if (invals[m].second < left)
                l = m + 1; // non-overlapping
            else {
                //  return true if [     )
                //                  [  )
                // if query spans over two intervals, it is definitely false
                return invals[m].first <= left && invals[m].second >= right;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        int n = invals.size();
        vector<pair<int, int>> tmp;
        for (int i = 0; i < n; ++i) {
            if (invals[i].first >= right) {
                // if [left right) was removed
                // we can still put [right  x)
                tmp.push_back(invals[i]);
            } else if (invals[i].second <= left) {
                // if [left right) is to be removed
                // we can still put [x  left)
                tmp.push_back(invals[i]);
            } else {
                // covers all 3 cases
                // [    )    or   [   ) or [     )
                //    [   )    [    )        [ )
                if (invals[i].first < left)
                    tmp.push_back({invals[i].first, left});
                if (invals[i].second > right)
                    tmp.push_back({right, invals[i].second});
            }
        }
        swap(invals, tmp);    
    }
};

// To do: ordered map solution
