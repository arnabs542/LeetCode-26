// Tags: Top-interview Heap Line-sweep D&C Amazon
// Time: O(nlogn), each point is added and removed only once
// Space: O(n)
// Priority queue (max heap) + line sweep
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        int i = 0, cur_X, cur_H, len = buildings.size();
        priority_queue<pair<int, int>> liveBlg; // max_heap
        while (i < len || !liveBlg.empty()) {
            if (liveBlg.empty() || i < len && buildings[i][0] <= liveBlg.top().second) {
                // *** processing at start point ***
                // If buildings[i] starts before or at the end of the top building
                // in the live queue, process this new building
                cur_X = buildings[i][0];
                while (i < len && buildings[i][0] == cur_X) {
                    // keep adding buildings starting at cur_X into the live
                    // queue, {height, end time}
                    liveBlg.push({buildings[i][2], buildings[i][1]});
                    ++i;
                }
            } else {
                // *** processing at end point ***
                // If buildings[i] starts after the end of the top building in the
                // live queue or i == len, process the building in the live queue
                cur_X = liveBlg.top().second;
                // (pop current building and also the ones that end before cur_X)
                while (!liveBlg.empty() && liveBlg.top().second <= cur_X)
                    liveBlg.pop();
            }
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
            // If change in height is observed, push {cur_X, cur_H} into
            // resulting vector
            if (res.empty() || res.back()[1] != cur_H)
                res.push_back({cur_X, cur_H});
        }
        return res;
    }
};

/*
The idea is to do "line sweep" and process the buildings only at
the start and end points (and output to resulting vector when there are
changes in the height).

We use a priority queue to save all the buildings that are still "alive".
(overlapping)

The queue is sorted by its height and end time (the larger height first
and if equal height, the one with a bigger end time first)


For each iteration, 
* We first find the current process time (cur_X), which is either the next new 
  building start time or the end time of the top entry of the live queue.

* If the new building starts before the top one ends, then process
  the new building (just put them in the queue).

* Otherwise, If the new building start time is larger than the top one end time, then 
  process the one in the queue first (pop them until it is empty or you find the
  first one that ends after the new building); 

* After processing, output it to the resulting vector if the height changes
  (height changes when either
   the new building added is taller than all other building overlapping at that start 
   point or
   a building is removed)
*/

// To do: Divide & Conquer solution
