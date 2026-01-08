class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> prev(n, INT_MIN);
        vector<int> curr(n, INT_MIN);
        prev[0] = nums1[0] * nums2[0];
        for (int j = 1; j < n; j++) {
            prev[j] = max(prev[j-1], nums1[0] * nums2[j]);
        }
        for (int i = 1; i < m; i++) {
            curr[0] = max(prev[0], nums1[i] * nums2[0]);
            
            for (int j = 1; j < n; j++) {
                int curr_product = nums1[i] * nums2[j];
                int take_both = max(curr_product, prev[j-1] + curr_product);
                int skip_i = prev[j];
                int skip_j = curr[j-1];
                
                curr[j] = max({take_both, skip_i, skip_j});
            }
            
            swap(prev, curr);
        }
        
        return prev[n-1];
    }
};