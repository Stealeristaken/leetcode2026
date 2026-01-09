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
    // Helper function returning {depth, LCA_node}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) {
            return {0, nullptr};
        }

        pair<int, TreeNode*> left = dfs(root->left);
        pair<int, TreeNode*> right = dfs(root->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        // If depths are equal, this node is the common ancestor
        if (leftDepth == rightDepth) {
            return {leftDepth + 1, root};
        }
        // If left is deeper, the answer is in the left subtree
        else if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        }
        // If right is deeper, the answer is in the right subtree
        else {
            return {rightDepth + 1, right.second};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};