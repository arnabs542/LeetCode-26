// Tags: Google Array
// Time: O(n), n = number of intervals
// Space: O(n)
class MyCalendar {
    // list of unsorted intervals
    vector<pair<int, int>> books;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto b : books) {
            // covers all 3 cases
            // [    )    or   [   ) or [     )
            //    [   )    [    )        [ )
            if (max(b.first, start) < min(b.second, end))
                return false;
        }
        books.push_back({start, end});
        return true;
    }
};
/*
Check every existing interval for overlap.
*/



// Time: O(logn)
// Space: O(n)
// Ordered map / Ordered set
class MyCalendar {
    map<int, int> books;
    // or set<pair<int, int>> books
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // element with key either equivalent to start or right after start
        auto it = books.lower_bound(start);
        // or auto it = books.lower_bound({start, end});

        if (it != books.end() && it->first < end)
            return false;
        // notice that the condition isn't it != books.begin()
        if (it != books.begin() && start < prev(it)->second)
            return false;

        books[start] = end;
        // or books.insert({start, end});
        return true;
    }
};
/*
If we keep existing intervals sorted, we only need to check 2 intervals:
one with start right before the new interval's start 
& one with start right after the new interval's start
*/
