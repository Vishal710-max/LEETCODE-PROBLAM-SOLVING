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
1. Since the input array is already sorted, the largest absolute values are at the ends.
2. Use two pointers:
   - Left pointer at the start.
   - Right pointer at the end.
3. Compare the absolute values of nums[left] and nums[right].
   - Square the larger absolute value and insert it at the end of the result array.
   - Move the pointer inward accordingly.
4. Continue until all elements are processed.
5. This way, we avoid sorting and directly construct the result in sorted order.

Time Complexity: O(n)  
Space Complexity: O(n) (result array; O(1) extra if we allow overwriting)

Key Insight:
The key idea is that the largest square comes from either the leftmost or rightmost element of the sorted array.
By filling the result from the back, we ensure correct non-decreasing order without sorting.

Example:
Input: nums = [-7,-3,2,3,11]
Process:
- Compare abs(-7)=7 and abs(11)=11 → square 11 → result[4]=121
- Compare abs(-7)=7 and abs(3)=3 → square 7 → result[3]=49
- Compare abs(-3)=3 and abs(3)=3 → square 3 → result[2]=9
- Compare abs(-3)=3 and abs(2)=2 → square 3 → result[1]=9
- Square 2 → result[0]=4
Output: [4,9,9,49,121]

Additional Notes:
- More efficient than the sorting method.
- Uses two-pointer technique, a common trick in array problems.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int pos = n - 1; // Fill result from the end
        
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos--] = nums[left] * nums[left];
                left++;
            } else {
                result[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        
        return result;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> result = sol.sortedSquares(nums);
    
    cout << "Output: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    
    return 0;
}
