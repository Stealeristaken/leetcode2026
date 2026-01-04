class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        count_3_colors = 6
        count_2_colors = 6
        
        # Iterate from n=2 to n
        for _ in range(n - 1):
            new_3_colors = (2 * count_3_colors + 2 * count_2_colors) % MOD
            new_2_colors = (2 * count_3_colors + 3 * count_2_colors) % MOD
            count_3_colors = new_3_colors
            count_2_colors = new_2_colors
            
        return (count_3_colors + count_2_colors) % MOD