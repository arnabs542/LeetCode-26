// Tags: Amazon String
// Time:  O(nlogn * l), n is the length of files, l is the average length of strings
// Space: O(l), to keep keys for the log (not sure)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // return an iterator to first elem of second group
        auto pivot = stable_partition(logs.begin(), logs.end(),
                                     [](const auto &log) {
                                         return isalpha(log.back());
                                     });
        sort(logs.begin(), pivot,
            [](const auto &a, const auto &b) {
                //or size_t i = a.find(' '), j = b.find(' ');
                size_t i = a.find_first_of(' '), j = b.find_first_of(' ');
                return a.substr(i + 1) != b.substr(j + 1) ?
                    a.substr(i + 1) < b.substr(j + 1) :
                    a.substr(0, i) < b.substr(0, j);
            });
        return logs;
    }
};


/*
a. Sorting: O(nlogn), n = number of logs in the List
b. Since keys of elements are logs itself, comparison between two keys
can take upto O(l) time.
c. Therefore overall O(l.nlogn)
*/
