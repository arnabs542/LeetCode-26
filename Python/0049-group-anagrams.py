# Time O(n*glog)
# Space O(n)
import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams_map, result = collections.defaultdict(list), []

        for s in strs:
            sorted_str = ''.join(sorted(s))
            anagrams_map[sorted_str].append(s)

        for anagrams in anagrams_map.values():
            anagrams.sort()
            result.append(anagrams)

        return result
        
