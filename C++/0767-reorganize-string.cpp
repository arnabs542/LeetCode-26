// Tags: String Heap Greedy Amazon
// Time: O(nlog26) ~ O(n)
// Space: O(26)
// Heap solution
class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, char>> max_heap;
        unordered_map<char, int> cnt;
        for (auto c: S)
            ++cnt[c];
        for (auto &[ch, freq]: cnt)
            max_heap.emplace(freq, ch);
        string res;
        pair<int, char> prev {0, ' '};
        while (!max_heap.empty()) {
            // choose the char with maximum freq
            auto cur = max_heap.top(); max_heap.pop();
            res += cur.second;
            // make the currently added char ineligible for
            // next step, by not adding it to the heap immediately
            --cur.first;
            // make the previously added one eligible for next step,
            // by adding it back to the heap
            if (prev.first > 0)
                max_heap.push(prev);
            prev = cur;
        }
        return res.length() == S.length() ? res : "";
    }
};

/*
Unlike 0621-task-schedular, where we placed all occurences of max freq element
at once, here we are placing each occurence one by one and also ensuring that
no two same char are placed together.
*/



// Time: O(n)
// Space: O(n)
// Greedy solution
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> cnt(26);
        // index to char with most freq
        int mostFreq = 0;
        for (char c: S)
            if (++cnt[c - 'a'] > cnt[mostFreq])
                mostFreq = c - 'a';
        // all mostFreq char's + gaps - 1 (for last occurence of mostFreq char)
        if (2*cnt[mostFreq] - 1 > S.size())
            return "";
        int i = 0;
        while (cnt[mostFreq]) {
            S[i] = 'a' + mostFreq;
            i += 2;
            --cnt[mostFreq];
        }
        for (int k = 0; k < 26; ++k) {
            while(cnt[k]) {
                if(i >= S.size()) i = 1;
                S[i] = 'a' + k;
                --cnt[k];
                i += 2;
            }
        }
        return S;
    }
};

/*
1. Count letter appearance and store in cnt[i]
2. Find the letter with largest occurence.
3. Put the letter into even indices (0, 2, 4 ...) of string. 
4. When idx reaches >= S.size, reset idx to 1 and start putting 
   the rest into string at odd indices (1, 3, 5)
*/
