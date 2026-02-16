# Day 047 - Reverse Bits

**Date:** February 16, 2026  
**LeetCode #:** 190  
**Difficulty:** Easy  
**Link:** [Reverse Bits](https://leetcode.com/problems/reverse-bits/)

---

## Problem Description

Reverse bits of a given 32 bits unsigned integer.

### Example 1:
```
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents 
the unsigned integer 43261596, so return 964176192 which its binary representation 
is 00111001011110000010100101000000.
```

### Example 2:
```
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
```

---

## Solution Approach

### Method: Bit Manipulation

The algorithm reverses bits one by one using bitwise operations:

1. **Initialize Result:** Start with `res = 0`

2. **Loop 32 Times:** Process each bit position:
   - Left shift result to make room: `res <<= 1`
   - Extract rightmost bit of n and add to result: `res |= (n & 1)`
   - Right shift n to process next bit: `n >>= 1`

3. **Return:** The reversed 32-bit integer

### Key Operations:
- `n & 1` - Gets the least significant bit
- `res <<= 1` - Shifts result left, making room for new bit
- `res |= bit` - Appends the bit to result

### Time Complexity
- **O(1)** - Fixed 32 iterations regardless of input

### Space Complexity
- **O(1)** - Only using a single integer variable
