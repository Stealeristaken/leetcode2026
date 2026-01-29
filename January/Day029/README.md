# Day 029 - Minimum Cost to Convert String I

**Date:** January 29, 2026  
**LeetCode #:** 2976  
**Difficulty:** Medium  
**Link:** [Minimum Cost to Convert String I](https://leetcode.com/problems/minimum-cost-to-convert-string-i/)

---

## Problem Description

You are given two **0-indexed** strings `source` and `target`, both of length `n` and consisting of **lowercase** English letters. You are also given two **0-indexed** character arrays `original` and `changed`, and an integer array `cost`, where `cost[i]` represents the cost of changing the character `original[i]` to the character `changed[i]`.

Return the **minimum cost** to convert the string `source` to the string `target` using any number of operations. If it is impossible, return `-1`.

### Example 1:
```
Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: 
- Change 'b' to 'c' at cost 5
- Change 'c' to 'e' at cost 1  
- Change 'd' to 'e' at cost 20
Total cost = 5 + 1 + 20 + 2 = 28
```

### Example 2:
```
Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: Change each 'a' to 'c' (cost 1), then 'c' to 'b' (cost 2). Total: 4 × 3 = 12.
```

### Example 3:
```
Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: Cannot convert 'd' to 'e'.
```

---

## Solution Approach

### Method: Graph + Dijkstra with Memoization

Model character transformations as a weighted directed graph and find shortest paths between character pairs.

### Key Insight:

Each character transformation `original[i] → changed[i]` with `cost[i]` is a directed edge in a graph. Finding the minimum cost to change character `a` to `b` is equivalent to finding the shortest path from `a` to `b`.

### Algorithm:

1. **Build transformation graph:**
   - Create adjacency list where `graph[c1][c2] = min cost` to directly change `c1` to `c2`
   - Handle duplicate edges by keeping minimum cost

2. **Dijkstra for shortest paths:**
   - For each unique `(source_char, target_char)` pair needed
   - Run Dijkstra to find minimum transformation cost
   - Cache results to avoid recomputation

3. **Calculate total cost:**
   - For each position `i` where `source[i] != target[i]`
   - Look up (or compute) shortest path cost
   - If any transformation is impossible, return `-1`
   - Sum all transformation costs

### Why Dijkstra:

- Transformations can be chained: `a → b → c` might be cheaper than direct `a → c`
- All costs are positive, making Dijkstra optimal
- Graph is small (≤26 nodes for lowercase letters)

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n + 26² · E log 26) | n for string scan, Dijkstra for up to 26² pairs |
| **Space** | O(26² + E) | Cache for all pairs + graph storage |

Where `n` is string length and `E` is number of transformation rules.

---

## Key Takeaways

- Character transformation problems often map to shortest path in graphs
- Memoization of shortest paths avoids redundant Dijkstra calls
- Graph with 26 nodes (alphabet) is small enough for per-pair shortest path
- Keep minimum cost when multiple edges exist between same nodes

---

## Files

- [solution.py](solution.py) - Python implementation
