// Tags: DP Google
/*
Time: O(2^n)
Naive Bfs
For each position we have two choices - either accelerate or reverse. So we can keep tack of
all possible positions of the racecar after n instructions and return the smallest n such that
the target position is reached.

Futher observations reveal that there may be overlapping among intermediate states so we can
memoize visited state (each state is characterized by car position and speed.)
*/



// Time: O(target*log(target)), in worst case all positions in range [0, 2*target] will be
//       visited and for each position, there can be as many as log(2*target) different speeds
// Space: O(target*log(target))
// Optimized Bfs
class Solution {
public:
    int racecar(int target) {
        // starts from position 0 with speed 1
        queue<pair<int, int>> q({{0, 1}});
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(1));
        
        for (int level = 0; !q.empty(); ++level) {
            for (int sz = q.size(); sz > 0; --sz) {
                auto [pos, speed] = q.front(); q.pop();
                if (pos == target)
                    return level;
                
                // 'A' instruction
                pair<int, int> next = {pos + speed, speed*2};
                string state = to_string(next.first) + " " + to_string(next.second);
                
                if (!visited.count(state) && 0 < next.first && next.first < (target << 1)) {
                    q.push(next);
                    visited.insert(state);
                }
                
                // 'R' instruction
                next = {pos, speed > 0 ? -1 : 1};
                state = to_string(next.first) + " " + to_string(next.second);
                if (!visited.count(state) && 0 < next.first && next.first < (target << 1)) {
                    q.push(next);
                    visited.insert(state);
                }
            }
        }
        return -1;
    }
};



// Time: O(target * (log(target))^2), for each i, m & q will log(i) different values each
// Space: O(target)
// Dp solution
class Solution {
    vector<int> memo;
    int dp(int i) {
        if (memo[i] != INT_MAX)
            return memo[i];
        // Note: if number of 'A's is m and initial position is 0, then final position is 2*m - 1
        // Case 1:
        // suppose m number of 'A' before first 'R'
        int j, p, m;
        for (m = 1; (j = (1 << m) - 1) < i; ++m) {
            for (int q = 0; (p = (1 << q) - 1) < j; ++q) {
                memo[i] = min(memo[i], m + 1 + q + 1 + dp(i - (j - p)));
            }
        }
        // m reaches highest value and
        // j becomes either equal to i or > i (next power of 2 - 1)
        // Case 2 or 3:
        memo[i] = min(memo[i], m + (i == j ? 0 : 1 + dp(j - i)));
        return memo[i]; 
    }
public:
    int racecar(int target) {
        memo.assign(target + 1, INT_MAX);
        return dp(target);
    }
};
/*
We notice that after each reverse, the car's speed returns to 1 or -1. So we can redefine the
problem in terms of the position of the car only while leaving out the speed.

dp[i] = length of the shortest instructions to move car from position 0 to position i, with
initial speed of 1 and its direction pointing towards position i.

By this definition, we can only apply dp[i] right after 'R' instruction and we need to make
sure the direction of initial speed is pointing towards the final target position.

We don't really know how many 'A' instructions there should be before the 'R' instruction, so
theoretically we need to try all possible cases: 0 A, 1 A, 2 A's, 3 A's and so on. for each
case, we can obtain the position of the car right before 'R' instruction, which will be
denoted as j = 2^m - 1, with m being the number of A's.

Depending on relation between i and j, there will be 3 cases:
1. j < i: car moves in the direction i then at jth position starts moving in reverse direction,
   then finally at j - p th position starts moving in the direction of i to reach ith position.

   Again, we don't really know how many 'A' instruction there should be in between these 2 'R'
   instructions, so we try eahc of the cases: 0 A, 1 A, 2 A's, 3 A's and so on.
   Assumer number of A is q. => p = 2^q - 1
   total len = m + 1 + q + 1 + dp[i - (j - p)]
   (both start and target position shifted so that start position is aligned with 0.)

2. j == i: target (ith) position is reached without any 'R' instructions.
   total len = m

3. j > i: 'R' instruction is issued after the car goes beyond i.
   total len = m + 1 + dp[j - i]
   (start and target positions shifted then swapped)

dp[i] = min(above 3 cases)

Base case:
dp[0] = 0
*/
