class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums) 

        i = 0 
        maxi = 1 

        for j in range(n):
            while nums[j] > nums [j] *k : 
                i += 1 
            maxi = max(maxi, j-i+1)

        return n - maxi 