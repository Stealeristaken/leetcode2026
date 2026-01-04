from typing import List

class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        total_sum = 0
        
        for num in nums:
            # Initialize count and sum for the current number
            count = 0
            current_div_sum = 0
            
            # Iterate only up to the square root of num
            for i in range(1, int(num**0.5) + 1):
                if num % i == 0:
                    # If i is a divisor, check if it's a perfect square root
                    if i * i == num:
                        count += 1
                        current_div_sum += i
                    else:
                        # Add both the divisor i and its pair (num // i)
                        count += 2
                        current_div_sum += i + (num // i)
                    
                    # Optimization: If count exceeds 4, we can stop checking this number
                    if count > 4:
                        break
            
            # If we found exactly 4 divisors, add their sum to the answer
            if count == 4:
                total_sum += current_div_sum
                
        return total_sum