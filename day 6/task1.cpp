/*
LeetCode Problem: 565. Array Nesting
Problem Link: https://leetcode.com/problems/array-nesting/

Description:
You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]], ... } subjected to the following rule:
- The first element in s[k] starts with the selection of the element nums[k] of nums.
- The next element in s[k] should be nums[nums[k]], and then nums[nums[nums[k]]], and so on.
- We stop adding right before a duplicate element occurs in s[k].

Return the longest length of a set s[k].

Approach:
1. Graph Theory Insight: The array represents a directed graph where each node i has an edge to node nums[i].
   This structure guarantees that the graph consists of several disjoint cycles.
2. Goal: Find the length of the longest cycle.
3. Algorithm:
   - Use a visited array to keep track of processed indices to avoid recomputation.
   - Iterate through each index. If an index is unvisited, it signifies the start of a new cycle.
   - Traverse the entire cycle starting from that index:
        * Mark each node as visited.
        * Move to the next node (nums[current]).
        * Count the length of the cycle.
   - Update the maximum cycle length found.
4. Key Optimization: The visited array ensures each node is processed only once, leading to linear time complexity.

Time Complexity: O(n), where n is the length of the array. Each element is visited exactly once.
Space Complexity: O(n), due to the visited array of size n.

Key Insight:
Since the graph is made of disjoint cycles, traversing from an unvisited node will reveal the entire cycle it belongs to.
Marking nodes as visited during traversal prevents reprocessing the same cycle.

Example:
Input: nums = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
The longest set is s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0} of length 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int MaxCount = 0;
        vector<bool> visited(n, false); // Tracks visited nodes to avoid reprocessing cycles
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Start traversal only for unvisited nodes (new cycles)
                int start = i;
                int count = 0;
                // Traverse the entire cycle
                while (!visited[start]) {
                    visited[start] = true; // Mark the current node as visited
                    start = nums[start];   // Move to the next node in the cycle
                    count++;               // Increment the cycle length counter
                }
                MaxCount = max(MaxCount, count); // Update the maximum cycle length found
            }
        }
        return MaxCount;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Example from the problem
    vector<int> nums1 = {5, 4, 0, 3, 1, 6, 2};
    cout << "Test case 1: [5,4,0,3,1,6,2] -> " << solution.arrayNesting(nums1) << endl;
    // Expected output: 4
    
    // Test case 2: A single long cycle
    vector<int> nums2 = {0, 1, 2, 3, 4, 5}; // Represents cycle 0->1->2->3->4->5->0
    cout << "Test case 2: [0,1,2,3,4,5] -> " << solution.arrayNesting(nums2) << endl;
    // Expected output: 6
    
    // Test case 3: Multiple self-loops and small cycles
    vector<int> nums3 = {1, 0, 3, 4, 2}; // Cycles: (0->1->0), (2->3->4->2)
    cout << "Test case 3: [1,0,3,4,2] -> " << solution.arrayNesting(nums3) << endl;
    // Expected output: 3 (from cycle 2->3->4->2)
    
    return 0;
}

/*
Test case 1: [5,4,0,3,1,6,2] -> 4
Test case 2: [0,1,2,3,4,5] -> 6
Test case 3: [1,0,3,4,2] -> 3
 */