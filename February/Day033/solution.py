from typing import List
from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        k -= 2
        cost = nums.pop(0)
        res = float("inf")
        window = SortedList(nums[:dist])
        cost += sum(window[:k])
        
        for left, right in zip(nums, nums[dist:]):
            window.add(right)
            cost += min(window[k], right) 
            res = min(res, cost)
            cost -= min(window[k], left)
            window.remove(left)
        return res