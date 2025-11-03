/*
Platform: LeetCode
Problem Name: 2860. Happy Students (Similar Variant: Maximize the Number of Distinct Elements After Operations)
Problem Link: https://leetcode.com/problems/happy-students/ (related concept)
Problem Code: Custom Implementation

Description:
You are given an array `nums` and an integer `k`.  
You may **increase or decrease** each element by at most `k` (i.e., change `nums[i]` to any value in the range `[nums[i] - k, nums[i] + k]`).

Your goal is to maximize the number of **distinct elements** in the array after performing the operations.

Return the **maximum number of distinct elements** that can be obtained.

Example 1:
Input: nums = [2, 4, 6], k = 1
Output: 3
Explanation:
We can make the array [1, 4, 7].
All are distinct → maximum distinct count = 3.

Example 2:
Input: nums = [1, 1, 1, 1], k = 2
Output: 3
Explanation:
We can change elements to [−1, 0, 1, 2].
Distinct count = 4, but due to overlapping possible ranges, only 3 are feasible.

Approach:
1. Sort the array so we process numbers in increasing order.
2. Maintain a variable `current` to track the last chosen distinct value.
3. For each number `x`:
   - Try to place a new distinct number as small as possible within `[x - k, x + k]`,
     but strictly greater than `current` to ensure distinctness.
   - If `place <= x + k`, we can place it and increment the count.
4. Return the count of distinct values placed.

Time Complexity: O(n log n)
    - Sorting the array dominates the runtime.
Space Complexity: O(1)
    - Only constant extra space used.

Key Insight:
The greedy choice ensures maximum distinct elements by always placing the next possible
smallest number greater than the previous one, without violating range limits.

Example Walkthrough:
Input: nums = [1, 3, 5], k = 1
Sorted: [1, 3, 5]
Start with current = very small value
For 1 → place = max(0, -inf+1) = 0 → valid → current = 0
For 3 → place = max(2, 1) = 2 → valid → current = 2
For 5 → place = max(4, 3) = 4 → valid → current = 4
Result = 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long current = LLONG_MIN / 2;  // Very small number
        int distinct = 0;

        for (long long x : nums) {
            long long place = max(x - (long long)k, current + 1);
            if (place <= x + k) {
                distinct++;
                current = place;
            }
        }

        return distinct;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<int> nums1 = {2, 4, 6};
    int k1 = 1;
    cout << "Input: [2, 4, 6], k = 1" << endl;
    cout << "Output: " << sol.maxDistinctElements(nums1, k1) << endl << endl;

    vector<int> nums2 = {1, 1, 1, 1};
    int k2 = 2;
    cout << "Input: [1, 1, 1, 1], k = 2" << endl;
    cout << "Output: " << sol.maxDistinctElements(nums2, k2) << endl << endl;

    vector<int> nums3 = {1, 3, 5};
    int k3 = 1;
    cout << "Input: [1, 3, 5], k = 1" << endl;
    cout << "Output: " << sol.maxDistinctElements(nums3, k3) << endl;

    return 0;
}
