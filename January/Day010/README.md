# Day 010 - Minimum ASCII Delete Sum for Two Strings

**Date:** January 10, 2026  
**LeetCode #:** 712  
**Difficulty:** Medium  
**Link:** [Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

---

## Problem Description

Given two strings `s1` and `s2`, return the **lowest ASCII sum of deleted characters** to make two strings equal.

### Example 1:
```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal to "ea", and 115 + 116 = 231.
```

### Example 2:
```
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100 + 101 + 101 = 302 to the sum.
Deleting "e" from "leet" adds 101 to the sum.
At the end, both strings are equal to "let", and 302 + 101 = 403.
```

---

## Solution Approach

### Method: Recursive DP with Memoization

Define `f(i, j)` as the minimum ASCII delete sum to make `s[i:]` and `t[j:]` equal.

### Transitions:

1. **Base case:** If either string is exhausted, delete all remaining characters
   - `f(len(s), j) = sum(ASCII of t[j:])`
   - `f(i, len(t)) = sum(ASCII of s[i:])`

2. **Characters match:** `s[i] == t[j]`
   - No deletion needed: `f(i+1, j+1)`

3. **Characters don't match:** Choose minimum of:
   - Delete `s[i]`: `ord(s[i]) + f(i+1, j)`
   - Delete `t[j]`: `ord(t[j]) + f(i, j+1)`

### Python's @cache Decorator:
- Automatically memoizes function results
- Avoids redundant calculations for overlapping subproblems

---

## ⏱️ Complexity Analysis

| Complexity | Value | Explanation |
|------------|-------|-------------|
| **Time** | O(m × n) | Each state (i, j) computed once |
| **Space** | O(m × n) | Memoization cache + recursion stack |

Where `m` and `n` are lengths of the two strings.

---

## Key Takeaways

- Classic string DP similar to Edit Distance / LCS
- Use ASCII values instead of counting deletions
- `@cache` decorator simplifies memoization in Python
- Base case handles remaining characters elegantly with `sum(map(ord, ...))`

---

## Files

- [solution.py](solution.py) - Python implementation
