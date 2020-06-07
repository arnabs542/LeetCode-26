# Time:  O(n^2)
# Space: O(n)

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda h_k: (-h_k[0], h_k[1]))
        result = []
        for p in people:
            result.insert(p[1], p)
        return result
