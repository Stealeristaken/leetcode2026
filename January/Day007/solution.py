# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        # List to store the sum of every subtree encountered
        all_sums = []

        # Helper function to calculate sums via Post-Order Traversal
        def subtree_sum(node):
            if not node:
                return 0
            
            # Recursively get sum of left and right subtrees
            left_sum = subtree_sum(node.left)
            right_sum = subtree_sum(node.right)
            
            # Current subtree sum = node value + left sum + right sum
            current_sum = node.val + left_sum + right_sum
            
            # Add to our list of sums
            all_sums.append(current_sum)
            
            return current_sum

        # 1. Calculate the total sum of the entire tree
        # The last value computed by the recursive function on 'root' is the total sum
        total_sum = subtree_sum(root)
        
        maximum_product = 0
        
        # 2. Iterate through all calculated subtree sums to find the max product
        for s in all_sums:
            # If we cut the edge above this subtree, the two parts are:
            # 's' and 'total_sum - s'
            product = s * (total_sum - s)
            maximum_product = max(maximum_product, product)
            
        # 3. Return result modulo 10^9 + 7
        return maximum_product % (10**9 + 7)