class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node):
            if not node:
                return 0, None

            ldepth, left = dfs(node.left)
            rdepth, right = dfs(node.right)
            
            ldepth += 1
            rdepth += 1

            if ldepth > rdepth:
                return ldepth, left
            elif rdepth > ldepth:
                return rdepth, right
            else:
                return ldepth, node
            
        return dfs(root)[1]