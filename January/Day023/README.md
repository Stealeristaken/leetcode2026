# Day 023 - Minimum Pair Removal to Sort Array II

**Date:** January 23, 2026  
**LeetCode #:** 3508  
**Difficulty:** Hard  
**Link:** [Minimum Pair Removal to Sort Array II](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/)

---

## Problem Description

Given an array `nums`, you can perform the following operation any number of times:

- Select the **adjacent pair** with the **minimum sum** and replace them with their sum.

Return the **minimum number of operations** needed to make the array **non-decreasing**.

### Example 1:
```
Input: nums = [5,2,3,1]
Output: 2
```

### Example 2:
```
Input: nums = [1,2,2]
Output: 0
```

---

## Solution Approach

### Method: Min-Heap + Doubly Linked List Simulation

Optimize Day022's brute force using a heap for efficient minimum finding and linked list for O(1) merges.

### Data Structures:

1. **Min-Heap:** Stores `(sum, index)` pairs for efficient minimum lookup
2. **Linked List Arrays:** `prv[i]` and `nxt[i]` track neighbors after deletions
3. **Removed Set:** `rmv[i]` marks deleted elements
4. **Bad Counter:** Tracks number of "violations" (descending pairs)

### Algorithm:

1. **Initialize:**
   - Build heap with all adjacent sums
   - Count initial violations (where `nums[i] > nums[i+1]`)

2. **While violations exist:**
   - Pop minimum sum pair from heap
   - Skip if either element is removed or sum is stale
   - Update violation count (remove old, add new)
   - Merge: update value, mark neighbor as removed
   - Update linked list pointers
   - Push new adjacent sums to heap

3. **Return** operation count

### Lazy Deletion:

Instead of removing from heap (expensive), we mark elements as removed and skip them when popped.

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(n log n) | Each element merged once, heap ops are O(log n) |
| **Space** | O(n) | Heap, linked list arrays, removed set |

Where `n` is the length of the input array.

---

## Key Takeaways

- Heap + linked list is powerful for "repeatedly find/remove minimum" problems
- Lazy deletion avoids expensive heap rebuilds
- Track "bad count" incrementally instead of checking sorted each time
- Doubly linked list enables O(1) neighbor updates after removal

---

## Files

- [solution.py](solution.py) - Python implementation
