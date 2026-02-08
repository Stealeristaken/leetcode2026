# Day 039 - Balanced Binary Tree

**Date:** February 8, 2026  
**LeetCode #:** 110  
**Difficulty:** Easy  
**Link:** [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

---

## Problem Description

Given a binary tree, determine if it is **height-balanced**.

A **height-balanced** binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

### Example 1:
```
Input: root = [3,9,20,null,null,15,7]
Output: true
```

### Example 2:
```
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
```

### Example 3:
```
Input: root = []
Output: true
```

---

## Solution Approach

### Method: DFS with Height Tracking

The algorithm uses a single DFS traversal that returns both the height and balance status:

1. **Base Case:** An empty node has height 0 and is balanced
2. **Recursive Case:** For each node:
   - Recursively get `(height, isBalanced)` from left and right subtrees
   - Current height = `1 + max(leftHeight, rightHeight)`
   - Current isBalanced = `leftBalanced && rightBalanced && |leftHeight - rightHeight| <= 1`
3. **Return:** The balance status of the root

### Key Optimization:
- Using a pair `{height, isBalanced}` avoids computing height twice
- Short-circuit evaluation: if any subtree is unbalanced, the whole tree is unbalanced

### Time Complexity
- **O(n)** - Visit each node exactly once

### Space Complexity
- **O(h)** - Recursion stack, where h is the height of the tree (O(log n) for balanced, O(n) worst case)

---

## Key Insights

1. **Single Pass:** By returning both height and balance status, we avoid redundant traversals
2. **Bottom-Up:** We check balance from leaves up to the root
3. **Early Termination:** Once a subtree is found unbalanced, we propagate that information upward

