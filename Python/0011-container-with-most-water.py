# Tags: Two-pointer
# Time O(n)
# Space O(1)
class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_area, i, j = 0, 0, len(height)-1

        while i<j:
            max_area = max(max_area,min(height[i],height[j]) * (j-i))
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
        return max_area
