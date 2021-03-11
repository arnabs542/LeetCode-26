// Tags: Bit-manipulation Amazon
// Time: O(n)
// Space: O(n)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        /* max_result is a record of the largest XOR we got so far.
         * (If it's 11100 at i = 2, it means before we reach the last two bits, 11100 is the
         * biggest XOR we have, and we're going to explore whether we can get another two 1's
         * and put them into max_result.)
         */
        int max_result = 0;
        int mask = 0;

        /* This is a greedy part, since we're looking for the largest XOR, we start from the
         * very beginning, aka, the 31st position of bits
         */
        for (int i = 31; i >= 0; --i) {
            // The mask will grow like 100.000, 110..000, 111..000, then 111...111
            // (used to capture the left parts)
            mask = mask | (1 << i);
            unordered_set<int> prefixes;
            // capture the left part as defined by mask
            for (int num : nums) {
                // we only care about the left parts, for example, if i = 2, then we have
                // {1100, 1000, 0100, 0000} from {1110, 1011, 0111, 0010}
                int left_part_of_num = num & mask;
                prefixes.insert(left_part_of_num);
            }
            // If i = 1 and before this iteration, the max_result we had was 1000 
            // (we didnt' get 1100), we wis the max_result to grow to 1010, so we ill try to
            // find a candidate (if exists) which can give us the greedy_try
            int greedy_try = max_result | (1 << i);
            // (This part is similar to Two Sum problem.)
            for (int p : prefixes) {
                /* Coming from a fact that if a ^ b = c, then a ^ c = b, now we have 'c',
                 * which is greedy_try, and we have 'a', which is p.
                 * If we hope a ^ b = c to be valid, then we need 'b', and to get 'b', we
                 * need a ^ c, if a ^ c existed in the set, then we're good to go.
                 */
                int another_num = p ^ greedy_try;
                if (prefixes.count(another_num)) {
                    max_result = greedy_try;
                    break;
                }
            }
            // if unfortunately, we didn't get the greedy_try, we still have our max_result
            // from previous iterations
        return max_result;
    }
};
