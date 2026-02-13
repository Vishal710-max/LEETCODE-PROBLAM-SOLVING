#include <iostream>
#include <vector>
using namespace std;

/*
3453. Separate Squares I
------------------------
We are given multiple squares in a 2D plane.
Each square is represented as:
    squares[i] = [xi, yi, li]
where:
    (xi, yi) = bottom-left coordinate
    li = side length

We must find the minimum y-coordinate of a horizontal line
such that:

    Total area above the line == Total area below the line

Overlapping areas are counted multiple times.
*/

/*
# Intuition
- The total area is fixed.
- If we draw a horizontal line at height h:
    - Some squares are completely above
    - Some completely below
    - Some partially split

We define:
    diff(h) = area_above - area_below

We want diff(h) = 0.

Observation:
- diff(h) is monotonic.
- So we can apply Binary Search on height.
*/

/*
# Approach
1. Determine search range:
    - low = 0
    - high = maximum (yi + li)

2. For a given height h:
    For each square:
        - If h <= bottom → full square above
        - If h >= top → full square below
        - Else → split square into two rectangles

3. Binary search for ~60 iterations (double precision).
4. Return low (or high).
*/

/*
# Complexity
- Let n = number of squares
- Each diff computation = O(n)
- Binary search runs ~60 iterations

Time:  O(60 * n)  ≈ O(n)
Space: O(1)
*/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0, high = 0;

        // Determine upper bound
        for (auto &sq : squares) {
            high = max(high, (double)sq[1] + sq[2]);
        }

        // Function to compute difference between areas
        auto diff = [&](double h) {
            double above = 0, below = 0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];

                if (h <= y) {
                    // Entire square above
                    above += l * l;
                }
                else if (h >= y + l) {
                    // Entire square below
                    below += l * l;
                }
                else {
                    // Line splits the square
                    below += l * (h - y);
                    above += l * (y + l - h);
                }
            }

            return above - below;
        };

        // Binary Search
        for (int i = 0; i < 60; i++) {
            double mid = (low + high) / 2;

            if (diff(mid) > 0)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};

// Driver code (for local testing)
int main() {
    Solution sol;

    vector<vector<int>> squares1 = {{0,0,1},{2,2,1}};
    cout << sol.separateSquares(squares1) << endl;  // Expected ~1.0

    vector<vector<int>> squares2 = {{0,0,2},{1,1,1}};
    cout << sol.separateSquares(squares2) << endl;  // Expected ~1.16667

    return 0;
}
