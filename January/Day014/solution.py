from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        # Coordinate Compression for X-axis
        # Collect all unique x-coordinates defined by the vertical edges of the squares
        xs = set()
        for x, y, l in squares:
            xs.add(x)
            xs.add(x + l)
        sorted_xs = sorted(list(xs))
        
        # Map specific x-values to their index in the sorted list
        x_map = {val: i for i, val in enumerate(sorted_xs)}
        n = len(sorted_xs) - 1  # Number of elementary intervals
        
        # Segment Tree Arrays
        # count: tracks how many active squares cover a specific interval node
        # length: tracks the actual geometric length covered by active squares in the node's range
        count = [0] * (4 * n)
        length = [0.0] * (4 * n)
        
        # Create Events: (y_coordinate, type, x_start_index, x_end_index)
        # type 1 for bottom edge (add), -1 for top edge (remove)
        events = []
        for x, y, l in squares:
            events.append((y, 1, x_map[x], x_map[x+l]))
            events.append((y + l, -1, x_map[x], x_map[x+l]))
            
        # Sort events by y-coordinate to process from bottom to top
        events.sort(key=lambda e: e[0])
        
        # Helper function to update the Segment Tree
        def update(node, start, end, l, r, val):
            if l >= end or r <= start:
                return
            if l <= start and end <= r:
                count[node] += val
            else:
                mid = (start + end) // 2
                update(2 * node, start, mid, l, r, val)
                update(2 * node + 1, mid, end, l, r, val)
            
            # Update the 'length' of the current node
            if count[node] > 0:
                # If this node is fully covered by at least one square, its active length is the full width
                length[node] = sorted_xs[end] - sorted_xs[start]
            else:
                # If not fully covered, the length is the sum of its children (if not a leaf)
                if start + 1 == end:
                    length[node] = 0.0
                else:
                    length[node] = length[2 * node] + length[2 * node + 1]

        total_area = 0.0
        strips = [] # To store (height_of_strip, width_of_union, start_y)
        prev_y = events[0][0]
        
        # Process events (Sweep Line)
        for y, val, l_idx, r_idx in events:
            dy = y - prev_y
            # current_width is the length of the union of x-intervals active before this y
            current_width = length[1] if n > 0 else 0.0
            
            if dy > 0:
                area_chunk = current_width * dy
                total_area += area_chunk
                strips.append((dy, current_width, prev_y))
            
            # Update the active intervals in the Segment Tree
            if n > 0:
                update(1, 0, n, l_idx, r_idx, val)
            prev_y = y
            
        # Find the split line
        target = total_area / 2.0
        current_area = 0.0
        
        for dy, width, y_start in strips:
            chunk = width * dy
            if current_area + chunk >= target:
                # The target area is reached within this strip
                needed = target - current_area
                # width * cut_height = needed  =>  cut_height = needed / width
                return y_start + (needed / width)
            current_area += chunk
            
        return float(prev_y)