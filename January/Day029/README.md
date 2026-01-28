# Day 029 - Find Minimum Time to Reach Last Room II

**Date:** January 29, 2026  
**LeetCode #:** 3342  
**Difficulty:** Hard  
**Link:** [Find Minimum Time to Reach Last Room II](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/)

---

## Problem Description

You are given a 2D grid of size `n x m` where `grid[i][j]` represents the cost to enter cell `(i, j)`. You start at `(0, 0)` with cost `0` and want to reach `(n-1, m-1)`.

You can move **right** or **down** to adjacent cells, paying the cost of the destination cell. Additionally, you have up to `k` **teleport** abilities that let you jump to any cell with value ≤ current cell's value for **free**.

Return the **minimum cost** to reach the destination, or `-1` if impossible.

### Example 1:
```
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: Minimum cost path using optimal teleports
```

---

## Solution Approach

### Method: Dijkstra's Algorithm with State Expansion (3D)

Extend Dijkstra to track position AND remaining teleports. Use sorted cell list for efficient teleport destination lookup.

### Key Insight:

Each state is `(i, j, teleports_used)` - same cell with different teleport counts may have different optimal costs. Teleporting to cells with value ≤ current value enables "free" jumps to advantageous positions.

### Algorithm:

1. **Preprocess:**
   - Flatten grid into `(value, i, j)` tuples
   - Sort by value for efficient teleport destination lookup

2. **3D Distance Array:**
   - `dist[i][j][k]` = minimum cost to reach `(i, j)` with `k` teleports used

3. **Dijkstra with extended states:**
   - Process `(cost, teleports_used, i, j)` from min-heap
   - **Normal moves:** Go right/down, pay destination cell cost
   - **Teleport:** If teleports remaining, jump to any cell with value ≤ current (free)

4. **Optimization:**
   - Track visited index per teleport count to avoid re-processing
   - Skip cells already visited at better cost

5. **Return** cost when reaching `(n-1, m-1)`

### Why 3D State Space:

Different paths to same cell may leave different teleports available. A path that "saves" teleports for later might be globally better even if locally more expensive.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n·m·k · log(n·m·k)) | Dijkstra over 3D state space |
| **Space** | O(n·m·k) | Distance array for all states |

Where `n×m` is grid size and `k` is maximum teleports.

---

## Key Takeaways

- State expansion (adding dimensions) handles "resource" problems in shortest path
- Sorting destinations enables efficient teleport target enumeration
- Lazy processing with visited tracking avoids redundant computation
- Dijkstra naturally extends to multi-dimensional state spaces

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
