class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        for (int i = 0; i < points.size() - 1; i++) {
            // Get current point and next point coordinates
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];
            
            // Calculate absolute differences
            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);
            
            // Add the maximum of the two differences to total time
            totalTime += max(dx, dy);
        }
        
        return totalTime;
    }
};