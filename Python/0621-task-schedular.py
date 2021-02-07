# Tags: Greedy Array
# Time:  O(n)
# Space: O(26) = O(1)
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        char_map = [0] * 26
        for c in tasks:
            char_map[ord(c) - ord('A')] += 1

        char_map.sort(reverse=True)
        # dont need to wait on the very last occurence
        # max_val is no of gaps (taking consecutive idle slots as a single gap)
        max_val = char_map[0] - 1
        # imagine every task we have to do after max val
        # task as idle slot (maximum possible idle slots)
        idle_slots = max_val * n

        # fill those idle_slots with actual number
        # (iterate larger to smaller values)
        for i in range(1, len(char_map)):
            idle_slots -= min(max_val, char_map[i])
            # in case there are more than one char
            # with max freq
            # as in that case, one elem will be outside
            # the idle slots

        # if we have more chars than idle_slots, no need
        # to put idle slots (tasks are already separated considering
        # we place them as A B C D A B C D A B C D, alternatively stacked)
        return idle_slots + len(tasks) if idle_slots > 0 else\
    len(tasks)


    """
    We always need atleast len(tasks) cpu cyles to finish the tasks.
    The question is how many idle slots we need ?
    Step 1 A _ _ A _ _ A
    Step 2 A B _ A B _ A B, where 1 B is outside
    """
