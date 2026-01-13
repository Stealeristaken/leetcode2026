class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        // Initialize bounds with the first square's values
        double min_y = squares[0][1];
        double max_y = (double)squares[0][1] + squares[0][2];
        
        // Calculate the total area and the search range [min_y, max_y]
        for (const auto& sq : squares) {
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            min_y = min(min_y, y);
            max_y = max(max_y, y + l);
        }
        
        double target = totalArea / 2.0;
        double low = min_y;
        double high = max_y;
        
        // Run Binary Search for a fixed number of iterations.
        // 100 iterations is more than enough to satisfy 10^-5 precision.
        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2.0;
            double currentAreaBelow = 0;
            
            for (const auto& sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;
                
                if (mid <= y) {
                    // The split line is below or at the bottom of this square
                    continue; 
                } else if (mid >= top) {
                    // The split line is above or at the top of this square
                    currentAreaBelow += l * l;
                } else {
                    // The split line cuts through this square
                    currentAreaBelow += l * (mid - y);
                }
            }
            
            // If the area below is greater than or equal to the target,
            // the solution might be this mid or something lower (to find the minimum).
            if (currentAreaBelow >= target) {
                high = mid;
            } else {
                low = mid;
            }
        }
        
        return high;
    }
};