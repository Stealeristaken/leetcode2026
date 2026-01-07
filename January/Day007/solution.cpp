/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Vector to store the sum of every subtree
    vector<long long> sums;

    // Helper function to compute subtree sums
    long long calculateSubtreeSum(TreeNode* node) {
        if (node == nullptr) return 0;

        // Recursively get left and right sums
        long long leftSum = calculateSubtreeSum(node->left);
        long long rightSum = calculateSubtreeSum(node->right);

        // Current subtree sum = node value + left + right
        long long currentSum = node->val + leftSum + rightSum;

        // Store the sum in our vector
        sums.push_back(currentSum);

        return currentSum;
    }

    int maxProduct(TreeNode* root) {
        sums.clear(); // Clear vector for safety

        // 1. Get total sum of the tree
        long long totalSum = calculateSubtreeSum(root);
        long long maxProd = 0;

        // 2. Iterate through all sums to find the maximum product
        // We use 'long long' because the product can exceed the 32-bit integer limit
        for (long long s : sums) {
            long long currentProd = s * (totalSum - s);
            maxProd = max(maxProd, currentProd);
        }

        // 3. Return result modulo 10^9 + 7
        return (int)(maxProd % 1000000007);
    }
};