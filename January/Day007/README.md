
# Day 007 - Maximum Product of Splitted Binary Tree

**Date:** January 7, 2026  
**LeetCode #:** 1339  
**Difficulty:** Medium  
**Link:** [Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/)

---

## Problem Description

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it **modulo** `10^9 + 7`.

**Note:** You need to maximize the answer before taking the mod and not after taking it.

### Example 1:
```
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
Their product is 110 (11*10=110).
```

### Example 2:
```
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.
Their product is 90 (15*6=90).
```

---

## Solution Approach

### Method: Post-Order Traversal + Two Pass

The key insight: When we cut an edge above a subtree with sum `S`, the two parts have sums `S` and `totalSum - S`.

### Algorithm:

1. **First Pass (Post-Order Traversal):**
   - Calculate sum of every subtree
   - Store all subtree sums in a list
   - The root's sum = total sum of entire tree

2. **Second Pass:**
   - For each subtree sum `s`, calculate product: `s × (totalSum - s)`
   - Track the maximum product

3. **Return:** Maximum product modulo `10^9 + 7`

### Why Post-Order?

- Post-order processes children before parent
- This allows us to calculate subtree sums bottom-up
- Each node's sum = its value + left subtree sum + right subtree sum

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n) | Two passes through the tree (both O(n)) |
| **Space** | O(n) | Store all subtree sums + recursion stack |

Where `n` is the number of nodes in the tree.

---

## Key Takeaways

- Splitting at edge above subtree S gives parts: S and (total - S)
- Post-order traversal naturally computes subtree sums
- Store all sums first, then find optimal split
- Apply modulo only at the end to avoid overflow issues during comparison

---

## Files

- [solution.cpp](solution.cpp) - C++ implementation
- [solution.py](solution.py) - Python implementation

