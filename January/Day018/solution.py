class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        # Prefix Sum
        row = [[0] * (n + 1) for _ in range(m)]
        col = [[0] * n for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                row[i][j + 1] = row[i][j] + grid[i][j]
                col[i + 1][j] = col[i][j] + grid[i][j]

        def isMagic(r, c, k):
            target = row[r][c + k] - row[r][c]

            # rows
            for i in range(r, r + k):
                if row[i][c + k] - row[i][c] != target:
                    return False

            # cols
            for j in range(c, c + k):
                if col[r + k][j] - col[r][j] != target:
                    return False

            # diagonals
            d1 = d2 = 0
            for i in range(k):
                d1 += grid[r + i][c + i]
                d2 += grid[r + i][c + k - 1 - i]
            return d1 == target and d2 == target

        max_size = min(m, n)

        for k in range(max_size, 1, -1):
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    if isMagic(i, j, k):
                        return k
        return 1