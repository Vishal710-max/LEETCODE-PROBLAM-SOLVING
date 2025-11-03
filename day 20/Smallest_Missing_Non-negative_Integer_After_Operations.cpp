/*
Platform: LeetCode
Problem Name: 2453. Smallest Missing Non-negative Integer After Operations
Problem Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
Problem Code: 2453

Description:
You are given an integer array `nums` and an integer `value`.

In one operation, you can add or subtract `value` from any element in `nums` any number of times.
After performing any number of operations, each element `nums[i]` can take any value that has 
the same remainder as `nums[i]` when divided by `value`.

Return the smallest non-negative integer that is *not present* in `nums` after performing any 
number of such operations.

Example 1:
Input: nums = [1,-10,7,13,6,8], value = 5
Output: 4
Explanation:
After modulo normalization by 5, nums becomes [1,0,2,3,1,3].
You can form numbers 0, 1, 2, 3 using available remainders, 
but cannot form 4 → so answer is 4.

Example 2:
Input: nums = [1,2,3,4,5], value = 1
Output: 5
Explanation:
All numbers have the same remainder (0 mod 1), so you can form 0,1,2,3,4, but not 5.

Approach:
1. Compute each number's remainder modulo `value`, making it positive with:
      remainder = ((x % value) + value) % value
2. Count frequency of each remainder in a hash map.
3. Initialize mex = 0.
4. For each integer mex starting from 0:
   - Determine its remainder (mex % value).
   - If there’s an unused number with that remainder, use it (freq[r]--).
   - Otherwise, stop — because that integer cannot be formed.
5. Return mex.

Time Complexity: O(n)
   - We visit each element once and then loop up to the smallest missing integer.
Space Complexity: O(value)
   - We store counts for each remainder in a hash map.

Key Insight:
Numbers can be freely shifted within their modulo class.  
So we can think in terms of “remainder buckets” —  
Each bucket lets us form one number for each available element of that remainder.

Example:
Input: nums = [3,0,3,2,4,2,1,1,0,4], value = 5
Output: 5
Explanation:
We can fill numbers 0 through 4 using available remainders. Next number 5 cannot be formed.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            int r = ((x % value) + value) % value; // normalize remainder
            freq[r]++;
        }

        int mex = 0;
        while (true) {
            int r = mex % value;
            if (freq[r] > 0)
                freq[r]--;  // use one number with this remainder
            else
                break;       // cannot form this number
            mex++;
        }
        return mex;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<int> nums1 = {1, -10, 7, 13, 6, 8};
    int value1 = 5;
    cout << "Input: nums = [1,-10,7,13,6,8], value = 5" << endl;
    cout << "Output: " << sol.findSmallestInteger(nums1, value1) << endl << endl;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int value2 = 1;
    cout << "Input: nums = [1,2,3,4,5], value = 1" << endl;
    cout << "Output: " << sol.findSmallestInteger(nums2, value2) << endl << endl;

    vector<int> nums3 = {3, 0, 3, 2, 4, 2, 1, 1, 0, 4};
    int value3 = 5;
    cout << "Input: nums = [3,0,3,2,4,2,1,1,0,4], value = 5" << endl;
    cout << "Output: " << sol.findSmallestInteger(nums3, value3) << endl;

    return 0;
}
