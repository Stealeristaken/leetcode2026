# Day 027 - Find Minimum Time to Reach Last Room I

**Date:** January 27, 2026  
**LeetCode #:** 3341  
**Difficulty:** Medium  
**Link:** [Find Minimum Time to Reach Last Room I](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/)

---

## Problem Description

There is a directed graph with `n` nodes labeled from `0` to `n - 1`. You are given an array `edges` where `edges[i] = [ui, vi, wi]` represents a directed edge from node `ui` to node `vi` with weight `wi`.

You can traverse an edge in the **reverse direction** by paying **double** the weight.

Return the **minimum cost** to reach node `n - 1` from node `0`. If it's impossible, return `-1`.

### Example 1:
```
Input: n = 4, edges = [[0,1,1],[1,2,2],[2,3,3]]
Output: 6
Explanation: Follow the path 0 → 1 → 2 → 3 with total cost 1 + 2 + 3 = 6.
```

### Example 2:
```
Input: n = 3, edges = [[0,1,5],[1,2,5],[0,2,1]]
Output: 1
Explanation: Direct path 0 → 2 costs 1.
```

---

## Solution Approach

### Method: Dijkstra's Algorithm with Modified Graph

Build a bidirectional graph where reverse edges cost double, then apply Dijkstra's shortest path algorithm.

### Key Insight:

The ability to traverse edges in reverse (at double cost) means we can model this as a graph where each directed edge `u → v` with weight `w` creates:
- A normal edge `u → v` with cost `w`
- A reverse edge `v → u` with cost `2w`

### Algorithm:

1. **Build adjacency list:**
   - For each edge `[u, v, w]`:
     - Add `(v, w)` to `adj[u]` (normal direction)
     - Add `(u, 2*w)` to `adj[v]` (reverse direction, double cost)

2. **Dijkstra's algorithm from node 0:**
   - Use min-heap with `(distance, node)` pairs
   - Track minimum cost to reach each node
   - Process nodes in order of increasing distance
   - Relax edges: if new path is shorter, update and push to heap

3. **Return** cost to reach node `n-1`, or `-1` if unreachable

### Why Dijkstra Works:

- All edge weights are positive (original and doubled)
- We need single-source shortest path
- Min-heap ensures we process nodes in optimal order

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O((V + E) log V) | Dijkstra with binary heap |
| **Space** | O(V + E) | Adjacency list and distance array |

Where `V = n` (nodes) and `E` = number of edges.

---

## Key Takeaways

- Reverse traversal at different cost can be modeled as additional edges
- Dijkstra's algorithm handles graphs with positive weighted edges
- Bidirectional edges with different costs are common in path problems
- Using `INT_MAX` as infinity helps detect unreachable nodes

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
