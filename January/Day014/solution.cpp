class Solution {
    vector<int> count;
    vector<double> length;
    vector<int> xs;

    // Segment Tree Update Function
    // node: current index in the segment tree array
    // start, end: the range of indices in the 'xs' array that this node covers (half-open interval [start, end))
    // l, r: the target range of indices in 'xs' to update
    // val: +1 to add a square layer, -1 to remove it
    void update(int node, int start, int end, int l, int r, int val) {
        if (l >= end || r <= start) return;
        
        if (l <= start && end <= r) {
            count[node] += val;
        } else {
            int mid = start + (end - start) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid, end, l, r, val);
        }

        // Calculate the length covered by this node
        if (count[node] > 0) {
            // If the count is positive, the entire interval is covered
            length[node] = (double)xs[end] - xs[start];
        } else if (start + 1 == end) {
            // Leaf node with count 0
            length[node] = 0.0;
        } else {
            // Internal node with count 0, sum of children
            length[node] = length[2 * node] + length[2 * node + 1];
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        // Step 1: Coordinate Compression for X-axis
        // Collect all unique x-coordinates to build elementary intervals
        set<int> x_set;
        for (const auto& sq : squares) {
            x_set.insert(sq[0]);
            x_set.insert(sq[0] + sq[2]); // x + l
        }
        xs.assign(x_set.begin(), x_set.end());
        int n = xs.size();

        // Step 2: Create Sweep Line Events
        // Each square generates two events: one for the bottom edge (entering) and one for the top (leaving)
        struct Event {
            int y, type, x_start, x_end;
            bool operator<(const Event& other) const {
                return y < other.y;
            }
        };
        vector<Event> events;
        events.reserve(2 * squares.size());

        for (const auto& sq : squares) {
            int y = sq[1];
            int l = sq[2];
            // Find indices in the compressed x-array
            int x1 = lower_bound(xs.begin(), xs.end(), sq[0]) - xs.begin();
            int x2 = lower_bound(xs.begin(), xs.end(), sq[0] + l) - xs.begin();
            events.push_back({y, 1, x1, x2});
            events.push_back({y + l, -1, x1, x2});
        }
        sort(events.begin(), events.end());

        // Step 3: Initialize Segment Tree
        // The tree needs to cover the ranges between unique x coordinates
        // Size is 4 * number of coordinates
        count.assign(4 * n, 0);
        length.assign(4 * n, 0.0);

        // Step 4: Process Events (Sweep Line)
        double total_area = 0;
        struct IntervalInfo {
            double dy, width, y;
        };
        vector<IntervalInfo> strips; // Store history to find the median later
        
        int prev_y = events[0].y;

        for (const auto& e : events) {
            int dy = e.y - prev_y;
            double current_width = length[1]; // length[1] is the root covering the full active width

            if (dy > 0) {
                total_area += current_width * dy;
                strips.push_back({(double)dy, current_width, (double)prev_y});
            }

            // Update the active intervals in the segment tree
            // We pass n-1 as the end because the intervals are formed by indices [0, 1), [1, 2), ..., [n-2, n-1)
            if (n > 1) {
                update(1, 0, n - 1, e.x_start, e.x_end, e.type);
            }
            prev_y = e.y;
        }

        // Step 5: Find the Y-coordinate that splits the area
        double target = total_area / 2.0;
        double current_area = 0;

        for (const auto& strip : strips) {
            double chunk_area = strip.width * strip.dy;
            if (current_area + chunk_area >= target) {
                double needed = target - current_area;
                // Area = width * height => height = Area / width
                return strip.y + (needed / strip.width);
            }
            current_area += chunk_area;
        }

        return (double)prev_y;
    }
};