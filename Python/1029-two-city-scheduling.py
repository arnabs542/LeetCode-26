# Time: O(nlogn)
# Space: O(1)
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        cmp = lambda cost: cost[0] - cost[1]
        # sort by cmp values of each elem
        costs.sort(key = cmp)
        costs_for_A = sum([ cost[0] for cost in costs[:len(costs)//2] ])
        costs_for_B = sum([ cost[1] for cost in costs[len(costs)//2:] ])
        return costs_for_A + costs_for_B
