/*
Platform: LeetCode
Problem Name: 3259. Maximum Number of Increasing Subarrays
Problem Link: https://leetcode.com/problems/maximum-number-of-increasing-subarrays/
Problem Code: 3259

Description:
You are given an integer array `nums`.

An "increasing subarray" is a contiguous part of the array where 
each element is strictly greater than the previous one.

We define two consecutive increasing subarrays as:
- The first subarray ending at index i
- The second subarray starting at index i + 1

Your task is to find the **maximum length k** such that there exist
two consecutive increasing subarrays of length k.

Return this maximum value of k.

Example 1:
Input: nums = [1,2,3,4,5,6]
Output: 3
Explanation:
- Increasing subarrays: [1,2,3], [4,5,6]
- Both have length 3 → maximum k = 3.

Example 2:
Input: nums = [1,2,1,2,3,4]
Output: 2
Explanation:
- Two increasing subarrays of length 2: [1,2] and [2,3]
- So, maximum k = 2.

Approach:
1. Use dynamic programming with two arrays:
   - `left[i]`: length of the longest increasing subarray ending at index i.
   - `right[i]`: length of the longest increasing subarray starting at index i.
2. Fill `left`:
   - If nums[i-1] < nums[i], then left[i] = left[i-1] + 1.
3. Fill `right`:
   - If nums[i] < nums[i+1], then right[i] = right[i+1] + 1.
4. For each adjacent pair (i, i+1):
   - Take k = min(left[i], right[i+1]).
   - Update ans = max(ans, k).
5. Return ans.

Time Complexity: O(n)
   - Each loop traverses the array once.
Space Complexity: O(n)
   - For `left` and `right` arrays.

Key Insight:
The overlap of increasing sequences at the boundary between i and i+1
determines the maximum k of consecutive increasing subarrays.

Example:
Input: nums = [1,2,3,1,2,3,4]
Output: 3
Explanation:
The two consecutive increasing subarrays of maximum length are:
[1,2,3] and [1,2,3,4], overlapping gives k = 3.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);
        
        // Compute lengths of increasing subarrays ending at i
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i])
                left[i] = left[i - 1] + 1;
        }

        // Compute lengths of increasing subarrays starting at i
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int ans = 0;
        // Check for adjacent increasing subarrays
        for (int i = 0; i < n - 1; ++i) {
            int k = min(left[i], right[i + 1]);
            ans = max(ans, k);
        }

        return ans;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    cout << "Input: [1,2,3,4,5,6]\nOutput: " 
         << sol.maxIncreasingSubarrays(nums1) << "\n\n";

    vector<int> nums2 = {1, 2, 1, 2, 3, 4};
    cout << "Input: [1,2,1,2,3,4]\nOutput: " 
         << sol.maxIncreasingSubarrays(nums2) << "\n\n";

    vector<int> nums3 = {1, 2, 3, 1, 2, 3, 4};
    cout << "Input: [1,2,3,1,2,3,4]\nOutput: " 
         << sol.maxIncreasingSubarrays(nums3) << "\n";

    return 0;
}
