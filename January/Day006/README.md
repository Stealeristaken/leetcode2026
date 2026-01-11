# Day 006 - Maximum Level Sum of a Binary Tree

**Date:** January 6, 2026  
**LeetCode #:** 1161  
**Difficulty:** Medium  
**Link:** [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

---

## Problem Description

Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `x` such that the sum of all the values of nodes at level `x` is **maximal**.

### Example 1:
```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1
Level 2 sum = 7 + 0 = 7
Level 3 sum = 7 + (-8) = -1
Maximum sum is at level 2.
```

### Example 2:
```
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2
```

---

## Solution Approach

### Method: BFS (Level Order Traversal)

Use **Breadth-First Search** to traverse the tree level by level, calculating the sum at each level:

1. **Initialize:** Queue with root node, track current level (starting at 1)
2. **Process each level:**
   - Pop all nodes at current level
   - Sum their values
   - Add their children to queue for next level
3. **Track maximum:** Update max sum and corresponding level when a larger sum is found
4. **Return:** The level with maximum sum (smallest level in case of tie)

### Why BFS?

- BFS naturally processes nodes level by level
- Using queue size to determine level boundaries
- Single pass through all nodes

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Visit each node exactly once |
| **Space** | O(w) | Queue stores at most one level, w = max width |

Where `n` is the number of nodes and `w` is the maximum width of the tree.

---

## Key Takeaways

- BFS is ideal for level-by-level tree traversal
- Track level boundaries using queue size at each iteration
- Initialize max with first level to handle negative sums correctly
- Return smallest level in case of ties (handled by `>` instead of `>=`)

---

## Files

- [solution.py](solution.py) - Python implementation

