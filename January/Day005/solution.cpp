

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (const auto& row : matrix) {
            for (int val : row) {
                // Add absolute value to total
                totalSum += abs(val);

                // Check if negative
                if (val < 0) {
                    negativeCount++;
                }

                // Update minimum absolute value found
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        // If we have an odd number of negatives, we must subtract the smallest value twice
        // (once because it was added as positive, and once to make it actual negative)
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};