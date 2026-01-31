# Day 031 - Find Smallest Letter Greater Than Target

**Date:** January 31, 2026  
**LeetCode #:** 744  
**Difficulty:** Easy  
**Link:** [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

---

## Problem Description

You are given an array of characters `letters` that is sorted in **non-decreasing order**, and a character `target`. There are **at least two different characters** in `letters`.

Return the **smallest character** in `letters` that is lexicographically **greater than** `target`. If such a character does not exist, return the **first character** in `letters`.

### Example 1:
```
Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
```

### Example 2:
```
Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
```

### Example 3:
```
Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
```

---

## Solution Approach

### Method: Binary Search

The algorithm uses **binary search** to efficiently find the smallest letter greater than target:

1. **Handle Edge Cases:** If target is greater than or equal to the last letter, or less than the first letter, return the first letter (wrap around)
2. **Binary Search:** Search for the insertion point where the next greater letter would be
   - If `letters[mid] > target`: move right boundary left (`j = mid - 1`)
   - If `letters[mid] <= target`: move left boundary right (`i = mid + 1`)
3. **Return Result:** After the loop, `i` points to the smallest letter greater than target

### Time Complexity
- **O(log n)** - Binary search halves the search space each iteration

### Space Complexity
- **O(1)** - Only using constant extra space

---

## Key Insights

1. **Sorted Array:** The problem guarantees a sorted array, making binary search the optimal approach
2. **Wrap Around:** If no greater letter exists, we wrap around to the first letter
3. **Strictly Greater:** We need a letter **strictly greater** than target (not equal)

