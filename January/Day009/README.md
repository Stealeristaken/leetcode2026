# Day 009 - Smallest Subtree with all the Deepest Nodes

**Date:** January 9, 2026  
**LeetCode #:** 865  
**Difficulty:** Medium  
**Link:** [Smallest Subtree with all the Deepest Nodes](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/)

---

## Problem Description

Given the `root` of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains **all the deepest nodes** in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

### Example 1:
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: The deepest nodes are 7 and 4.
Their lowest common ancestor is node 2.
```

### Example 2:
```
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
```

### Example 3:
```
Input: root = [0,1,3,null,2]
Output: [2]
```

---

## Solution Approach

### Method: DFS with Depth Tracking

Use post-order DFS to return both the **depth** and the **LCA candidate** from each subtree.

### Algorithm:

1. **Base case:** Null node returns depth 0 and nullptr
2. **Recursive case:** Get depth and LCA from left and right subtrees
3. **Compare depths:**
   - If `leftDepth == rightDepth`: Current node is the LCA
   - If `leftDepth > rightDepth`: LCA is in left subtree
   - If `rightDepth > leftDepth`: LCA is in right subtree
4. **Return:** Increment depth and propagate the correct LCA

### Why This Works:

- The deepest nodes will have the maximum depth
- If both subtrees have equal max depth, current node is their common ancestor
- If one subtree is deeper, the answer lies entirely in that subtree

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Visit each node exactly once |
| **Space** | O(h) | Recursion stack, h = height of tree |

Where `n` is the number of nodes and `h` is the height of the tree.

---

## Key Takeaways

- Elegant single-pass DFS solution
- Return multiple values (depth + node) from recursion
- Compare subtree depths to determine LCA
- Same problem as LeetCode #1123 (Lowest Common Ancestor of Deepest Leaves)

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation
