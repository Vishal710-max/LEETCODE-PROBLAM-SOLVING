/*
Platform: LeetCode
Problem Name: Sort Array By Parity
Problem Link: https://leetcode.com/problems/sort-array-by-parity/
Problem Code: 905

Description:
Given an integer array nums, move all the even integers to the beginning of the array,
followed by all the odd integers. Return any array that satisfies this condition.

Example:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: [4,2,3,1] is also an accepted output.

Approach:
We use a two-pointer method:
1. Initialize two pointers: left (start of the array), right (end of the array).
2. While left < right:
   - If nums[left] is odd and nums[right] is even → swap them.
   - If nums[left] is even → move left forward.
   - If nums[right] is odd → move right backward.
3. Continue until left >= right.
This ensures even numbers are grouped at the start and odds at the end.

Time Complexity: O(n) — each element is checked at most once.
Space Complexity: O(1) — in-place rearrangement without extra array.

Key Insight:
Use the parity property and two pointers to efficiently swap misplaced odd/even numbers
instead of building a new result array.

Example:
Input: nums = [3,1,2,4]
Process:
- left=0 (3 odd), right=3 (4 even) → swap → [4,1,2,3]
- left moves forward since nums[left]=4 (even).
- right moves backward since nums[right]=3 (odd).
Final array: [4,2,1,3] (valid).
Output: [4,2,1,3]

Additional Notes:
Multiple correct answers are possible since the problem allows any arrangement
with all evens first followed by odds.
*/
#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            // Swap if left is odd and right is even
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }
            
            // Move left pointer if already even
            if (nums[left] % 2 == 0) {
                left++;
            }
            // Move right pointer if already odd
            if (nums[right] % 2 == 1) {
                right--;
            }
        }
        
        return nums; // sorted in-place
    }
};

// Test Cases

int main() {
   cout<<"Here is the Main Function";
    Solution sol;
    vector<int> nums1 = {3,1,2,4};
    vector<int> nums2 = {0};
    vector<int> nums3 = {1,3,5,2,4,6};

    auto res1 = sol.sortArrayByParity(nums1); // Possible: [2,4,3,1]
    auto res2 = sol.sortArrayByParity(nums2); // [0]
    auto res3 = sol.sortArrayByParity(nums3); // Possible: [6,4,2,5,3,1]

    for (int x : res1) cout << x << " "; cout << endl;
    for (int x : res2) cout << x << " "; cout << endl;
    for (int x : res3) cout << x << " "; cout << endl;
}


