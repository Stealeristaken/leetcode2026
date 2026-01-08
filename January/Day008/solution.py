from typing import List

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        # dp[i][j] represents max dot product using elements up to index i in nums1 
        # and index j in nums2
        dp = [[float('-inf')] * n for _ in range(m)]
        dp[0][0] = nums1[0] * nums2[0]
        for j in range(1, n):
            dp[0][j] = max(dp[0][j-1], nums1[0] * nums2[j])
        for i in range(1, m):
            dp[i][0] = max(dp[i-1][0], nums1[i] * nums2[0])
        for i in range(1, m):
            for j in range(1, n):
                curr_product = nums1[i] * nums2[j]
                take_both = max(curr_product, dp[i-1][j-1] + curr_product)
                skip_i = dp[i-1][j]
                skip_j =  dp[i][j-1]
                
                dp[i][j] = max(take_both, skip_i, skip_j)
        
        return dp[m-1][n-1]