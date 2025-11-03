/*
Platform: LeetCode
Problem Name: 3258. Count Substrings That Satisfy K-Constraint II
(Alternate name: Has Increasing Subarrays of Length K — depending on contest/problem variant)
Problem Link: https://leetcode.com/problems/has-increasing-subarrays-of-length-k/
Problem Code: 3258 (or similar contest ID)

Description:
You are given an integer array `nums` and an integer `k`.

Your task is to determine if there exist **two consecutive subarrays** of length `k`
— such that both subarrays are **strictly increasing**.

Return `true` if such a pair of subarrays exists, otherwise return `false`.

Example 1:
Input: nums = [1,2,3,4,5,6], k = 2
Output: true
Explanation:
Subarrays [1,2] and [3,4] are both strictly increasing.

Example 2:
Input: nums = [1,3,2,4,5,7], k = 3
Output: false
Explanation:
No two consecutive subarrays of length 3 are both strictly increasing.

Approach:
1. Define a helper function `isIncreasing(nums, start, k)` that checks if the subarray
   starting at `start` of length `k` is strictly increasing.
   - Traverse the range [start, start + k - 1)
   - If any element nums[i] >= nums[i + 1], return false.
2. In `hasIncreasingSubarrays`:
   - Iterate over all valid starting indices i from 0 to n - 2*k
   - For each index i, check if:
       → `isIncreasing(nums, i, k)` AND `isIncreasing(nums, i + k, k)` are both true.
   - If yes, return true.
3. If no such pair exists, return false.

Time Complexity: O(n * k)
   - For each valid start, we check two subarrays of size k.
Space Complexity: O(1)
   - Constant extra space.

Key Insight:
By checking consecutive subarrays of size k one after another,
we can efficiently determine if the required pattern exists
without generating all subarrays explicitly.

Example:
Input: nums = [1,2,3,5,6,7,8,9], k = 3
Output: true
Explanation:
Subarrays [1,2,3] and [5,6,7] are both strictly increasing.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIncreasing(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; ++i) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i + 2 * k <= n; ++i) {
            if (isIncreasing(nums, i, k) && isIncreasing(nums, i + k, k))
                return true;
        }
        return false;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    int k1 = 2;
    cout << "Input: nums = [1,2,3,4,5,6], k = 2" << endl;
    cout << "Output: " << (sol.hasIncreasingSubarrays(nums1, k1) ? "true" : "false") << endl << endl;

    vector<int> nums2 = {1, 3, 2, 4, 5, 7};
    int k2 = 3;
    cout << "Input: nums = [1,3,2,4,5,7], k = 3" << endl;
    cout << "Output: " << (sol.hasIncreasingSubarrays(nums2, k2) ? "true" : "false") << endl << endl;

    vector<int> nums3 = {1, 2, 3, 5, 6, 7, 8, 9};
    int k3 = 3;
    cout << "Input: nums = [1,2,3,5,6,7,8,9], k = 3" << endl;
    cout << "Output: " << (sol.hasIncreasingSubarrays(nums3, k3) ? "true" : "false") << endl;

    return 0;
}
