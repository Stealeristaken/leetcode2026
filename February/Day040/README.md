# Day 040 - Balance a Binary Search Tree

**Date:** February 9, 2026  
**LeetCode #:** 1382  
**Difficulty:** Medium  
**Link:** [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

---

## Problem Description

Given the `root` of a binary search tree, return a **balanced** binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than `1`.

### Example 1:
```
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
```

### Example 2:
```
Input: root = [2,1,3]
Output: [2,1,3]
```

---

## Solution Approach

### Method: Inorder Traversal + Rebuild BST

The algorithm uses a two-step approach:

1. **Inorder Traversal:** Collect all nodes in sorted order using inorder traversal
   - Since it's a BST, inorder traversal gives us nodes in ascending order
   
2. **Build Balanced BST:** Recursively build a balanced BST from the sorted array
   - Pick the middle element as root
   - Recursively build left subtree from left half
   - Recursively build right subtree from right half

### Time Complexity
- **O(n)** - Inorder traversal O(n) + Building BST O(n)

### Space Complexity
- **O(n)** - Storing nodes O(n) + Recursive call stack O(log n)

---

## Key Insights

1. Inorder traversal of BST always gives sorted order
2. Building a balanced BST from sorted array is analogous to binary search
3. Always picking the middle element ensures minimum height
