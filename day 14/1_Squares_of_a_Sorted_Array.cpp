/*
Platform: LeetCode
Problem Name: 977. Squares of a Sorted Array
Problem Link: https://leetcode.com/problems/squares-of-a-sorted-array/
Problem Code: 977

Description:
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number, 
also in non-decreasing order.

Example:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: 
- Squaring each element gives [16,1,0,9,100].
- After sorting: [0,1,9,16,100].

Approach:
1. Traverse through the array.
2. Square each element using pow() or direct multiplication.
3. Store the squared values back into the array.
4. Use sort() to arrange the squared values in non-decreasing order.
5. Return the modified array.

Time Complexity: 
- O(n log n), because sorting dominates the runtime.

Space Complexity: 
- O(1) extra space (in-place modification).

Key Insight:
The array is sorted, but squaring may disrupt the order. Sorting after squaring ensures the correct sequence.

Example:
Input: nums = [-7,-3,2,3,11]
Process:
- Squared values: [49,9,4,9,121]
- Sorted result: [4,9,9,49,121]
Output: [4,9,9,49,121]

Additional Notes:
This solution uses sorting after squaring. 
An optimized approach would use two pointers (left and right) to directly place the largest squares at the correct position 
in O(n) time without explicit sorting.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = pow(nums[i], 2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(nums);
    
    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
