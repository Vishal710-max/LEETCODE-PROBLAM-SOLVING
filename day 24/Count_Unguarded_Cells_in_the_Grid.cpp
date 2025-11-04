/*
Platform: LeetCode
Problem Name: Count Unguarded Cells in the Grid
Problem Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
Problem Code: 2257

Description:
You are given an m x n grid, where:
- 0 represents an empty cell,
- 1 represents a wall,
- 2 represents a guard.

You are also given two integer arrays:
- guards: positions of guards in the grid.
- walls: positions of walls in the grid.

A guard can see horizontally and vertically in all four directions until:
- it hits a wall, or
- it hits another guard, or
- it reaches the edge of the grid.

Return the number of cells that are neither occupied by a wall or guard nor guarded by any guard.

Example:
Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7

Explanation:
The unguarded cells are marked as 0’s that are not visible to any guard.

Approach:
1. Create an m x n grid initialized to 0 (empty).
   - Mark walls as 1.
   - Mark guards as 2.
2. For each guard:
   - Move in all 4 directions (up, down, left, right).
   - Continue marking cells as “seen” until hitting a wall or another guard.
3. Count all cells that remain empty (0) and not seen (unguarded).

Time Complexity: O(m * n)
  - Each cell is visited at most once in each direction from guards.
Space Complexity: O(m * n)
  - For storing grid and visibility (seen) states.

Key Insight:
- The grid is small enough that a direct simulation works efficiently.
- Marking visibility in all four directions ensures full coverage.

Additional Notes:
- The same logic can be extended for more complex visibility rules.
- Guards and walls act as blocking elements.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 = empty, 1 = wall, 2 = guard

        // Mark walls and guards on the grid
        for (auto &w : walls)
            grid[w[0]][w[1]] = 1; 
        for (auto &g : guards)
            grid[g[0]][g[1]] = 2; 

        vector<vector<bool>> seen(m, vector<bool>(n, false)); // To mark guarded cells
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}}; // right, left, down, up

        // Simulate guard vision
        for (auto &g : guards) {
            int r = g[0], c = g[1];
            for (auto &d : directions) {
                int nr = r + d[0], nc = c + d[1];
                // Continue in direction until hitting a wall or guard
                while (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 1 && grid[nr][nc] != 2) {
                    seen[nr][nc] = true;
                    nr += d[0];
                    nc += d[1];
                }
            }
        }

        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && !seen[i][j])
                    unguarded++;
            }
        }

        return unguarded;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;

    vector<vector<int>> guards1 = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls1 = {{0,1},{2,2},{1,4}};
    cout << "Output 1: " << sol.countUnguarded(4, 6, guards1, walls1) << endl; // Expected: 7

    vector<vector<int>> guards2 = {{0,0},{1,2}};
    vector<vector<int>> walls2 = {{0,1}};
    cout << "Output 2: " << sol.countUnguarded(3, 3, guards2, walls2) << endl; // Example custom test

    return 0;
}
