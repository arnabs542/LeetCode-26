// Tags: Hash-table Design Google
// Time: O(1)
// Space: O(n), n is the number of all unique messages seen over time
class Logger {
    unordered_map<string, int> msg_time;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (msg_time.count(message) && timestamp < msg_time[message] + 10 ) {
            // not printed
            return false;
        }
        // printed
        msg_time[message] = timestamp;
        return true;
    }
};



// Time:  O(1), amortized
// Space: O(k), k is the max number of printed messages in last 10 seconds
class Logger {
    unordered_set<string> printed;
    queue<pair<int, string>> q;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!q.empty() && q.front().first <= timestamp - 10) {
            printed.erase(q.front().second);
            q.pop();
        }
        if (printed.count(message))
            return false;
        printed.insert(message);
        q.push({timestamp, message});
        return true;
    }
};
