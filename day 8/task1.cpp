/*
Platform: LeetCode
Problem Name: Non-decreasing Array
Problem Link: https://leetcode.com/problems/non-decreasing-array/
Problem Code: 665

Description:
Given an array `nums` with `n` integers, check if it could become non-decreasing by modifying at most one element.
An array is non-decreasing if `nums[i] <= nums[i+1]` for every `i` (0-based) such that `0 <= i <= n-2`.

Approach:
1. Initialize a counter `c` to track the number of modifications.
2. Iterate through the array starting from the second element (index 1).
3. For each element, if a violation is found (i.e., `nums[i-1] > nums[i]`):
   a. Increment the modification count `c`.
   b. If `c` exceeds 1, return false immediately.
   c. To fix the violation:
        - If we are at the second element (i=1) or if the element two positions behind (`nums[i-2]`) is <= current element (`nums[i]`), then set `nums[i-1] = nums[i]` (decrease the previous element).
        - Otherwise, set `nums[i] = nums[i-1]` (increase the current element).
4. If the loop completes without exceeding one modification, return true.

Time Complexity: O(n) - We traverse the array once.
Space Complexity: O(1) - Only a few variables are used.

Key Insight:
When a violation is found, the decision to change either the previous or the current element depends on the context of the elements before to avoid creating new violations. This ensures minimal changes.

Example:
Input: nums = [4,2,3]
- At i=1: nums[0]=4 > nums[1]=2 → violation.
  Since i=1 < 2, set nums[0]=2 → array becomes [2,2,3].
- No further violations → return true.

Additional Notes:
The solution efficiently handles edge cases and ensures at most one change is made.
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c = 0; // Count of modifications
        int n = nums.size(); // Size of the vector
        for (int i = 1; i < n; i++) {
            if (nums[i-1] > nums[i]) { // Check for violation
                c++; // Increment modification count
                if (c > 1) { // If more than one modification is needed, return false
                    return false;
                }
                // Decide how to fix the violation
                if (i < 2 || nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i]; // Decrease the previous element
                } else {
                    nums[i] = nums[i-1]; // Increase the current element
                }
            }
        }
        return true; // If we get here, it's possible with at most one modification
    }
};

/*
Test Cases:
1. Input: [4,2,3] → Output: true
2. Input: [4,2,1] → Output: false
3. Input: [3,4,2,3] → Output: false
4. Input: [5,7,1,8] → Output: true
5. Input: [1,2,3,4] → Output: true
6. Input: [1,3,2] → Output: true
7. Input: [2,3,3,2,4] → Output: true
*/