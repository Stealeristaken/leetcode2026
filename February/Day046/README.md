# Day 046 - Add Binary

**Date:** February 15, 2026  
**LeetCode #:** 67  
**Difficulty:** Easy  
**Link:** [Add Binary](https://leetcode.com/problems/add-binary/)

---

## Problem Description

Given two binary strings `a` and `b`, return their sum as a binary string.

### Example 1:
```
Input: a = "11", b = "1"
Output: "100"
```

### Example 2:
```
Input: a = "1010", b = "1011"
Output: "10101"
```

---

## Solution Approach

### Method: Python Built-in Conversion

The algorithm leverages Python's built-in functions for a concise solution:

1. **Convert to Integer:** Use `int(a, 2)` to convert binary string to integer
   - The second parameter `2` specifies base-2 (binary)

2. **Add:** Perform integer addition

3. **Convert Back:** Use `bin()` to convert result back to binary string
   - `bin()` returns a string prefixed with "0b"
   - Slice `[2:]` removes the "0b" prefix

### Time Complexity
- **O(n)** - Where n is the length of the longer string (conversion operations)

### Space Complexity
- **O(n)** - Storage for the result string
