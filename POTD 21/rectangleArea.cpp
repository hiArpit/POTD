class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of first rectangle
        long long area1 = 1LL * (ax2 - ax1) * (ay2 - ay1);

        // Area of second rectangle
        long long area2 = 1LL * (bx2 - bx1) * (by2 - by1);

        // Calculate overlapping width and height
        int overlapX1 = max(ax1, bx1);
        int overlapX2 = min(ax2, bx2);
        int overlapY1 = max(ay1, by1);
        int overlapY2 = min(ay2, by2);

        // Overlapping area (0 if rectangles do not overlap)
        int overlapArea =
            max(0, overlapX2 - overlapX1) *
            max(0, overlapY2 - overlapY1);

        // Total area = area of both rectangles - overlapping area
        return area1 + area2 - overlapArea;
    }
};

/*
Time Complexity: O(1)
- Only constant number of arithmetic and comparison operations are performed.

Space Complexity: O(1)
- Only constant extra variables are used.
*/