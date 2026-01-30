# Day 030 - Minimum Cost to Convert String II

**Date:** January 30, 2026  
**LeetCode #:** 2977  
**Difficulty:** Hard  
**Link:** [Minimum Cost to Convert String II](https://leetcode.com/problems/minimum-cost-to-convert-string-ii/)

---

## Problem Description

You are given two **0-indexed strings** `source` and `target` consisting of lowercase English letters. You are also given two arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` is the cost of converting the string `original[i]` to the string `changed[i]`.

You start with the string `source`. In one operation, you can pick a **substring** of `source` and convert it to the corresponding string in `changed` using the corresponding cost from `cost`. You can perform any number of operations, but each substring of `source` can only be converted at most **once**.

Return the **minimum cost** to convert `source` to `target`. If it is impossible, return `-1`.

---

## Solution Approach

### Method: Graph + Dynamic Programming

The algorithm uses **all-pairs shortest paths** combined with **DP to find the minimum cost**:

1. **Build a Graph:** Create a directed graph where nodes are strings and edges represent transformations with costs
2. **All-Pairs Shortest Paths:** Run **Dijkstra's algorithm from each unique string** to compute the minimum cost to convert between any two strings
3. **Precompute Valid Lengths:** Store all possible substring lengths from the `original` array
4. **DP on Positions:** Use `dp[i]` to represent the minimum cost to transform `source[0...i-1]` to `target[0...i-1]`
   - If `source[i] == target[i]`, we can move to `dp[i+1]` without cost
   - Otherwise, try all possible substring conversions and take the minimum

### Time Complexity
- Building graph: O(m)
- Dijkstra from each node: O(n² log n) where n is the number of unique strings
- DP: O(m × l × len) where m is source length, l is number of valid lengths
- **Overall: O(n² log n + m × l × len)**

### Space Complexity
- Graph and distance matrix: O(n²)
- DP array: O(m)

---

## Key Insights

1. **Graph Representation:** Treat string conversions as a shortest path problem
2. **Early Return Optimization:** Once a substring is converted, we move past it in the DP
3. **Edge Case Handling:** If no valid conversion exists between two strings, the distance remains infinity and that path is not considered

