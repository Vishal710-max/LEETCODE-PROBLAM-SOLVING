/*
Platform: LeetCode
Problem Name: 3347. Maximum Frequency of an Element After Performing Operations II
Problem Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/
Problem Code: 3347

Description:
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:
    - Select an index i that was not selected in any previous operations.
    - Add an integer in the range [-k, k] (inclusive) to nums[i].

Your goal is to maximize the frequency of the most frequent element after performing all operations.

Return the maximum possible frequency of an element after performing exactly numOperations operations.

Approach:
1. **Sorting**:
   - First, sort the input array `nums` to efficiently analyze number ranges and possible frequency increases.

2. **Counting Frequencies**:
   - Traverse through `nums` and count consecutive duplicates using an `unordered_map` to record their frequencies.

3. **Mode Candidates**:
   - For each unique value in `nums`, consider possible “mode” candidates:
     - The number itself (`value`)
     - The number adjusted by ±k (`value - k` and `value + k`) within bounds.
   - This helps explore all potential targets to maximize frequency.

4. **Binary Search for Range**:
   - For each mode candidate, find:
     - `leftBound` → first index where elements ≥ (mode - k)
     - `rightBound` → last index where elements ≤ (mode + k)
   - This range includes all numbers that can be converted into the mode.

5. **Frequency Calculation**:
   - For each mode candidate, calculate:
     - The number of elements in the range `[leftBound, rightBound]`.
     - Use available `numOperations` to increase frequency up to the range limit.
   - Update the global maximum frequency `ans`.

Time Complexity: O(n log n)
- Sorting takes O(n log n)
- Range checks with binary search take O(log n)
- Overall efficient for n ≤ 10⁵

Space Complexity: O(n)
- Using maps, sets, and helper structures proportional to input size.

Key Insight:
By exploring all potential target values (modes) within ±k of each unique number, and using binary search to determine how many numbers can be adjusted into that target range, we can compute the maximum achievable frequency efficiently.

Example:
Input:
nums = [1, 4, 8, 13]
k = 3
numOperations = 2

Step-by-step:
- Possible adjustments allow numbers to move within ±3.
- Using 2 operations, we can bring 4 → 7 and 8 → 7, making three 7s.
Output:
3

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int> numCount;
        set<int> modes;

        auto addMode = [&](int value) {
            modes.insert(value);
            if (value - k >= nums.front()) {
                modes.insert(value - k);
            }
            if (value + k <= nums.back()) {
                modes.insert(value + k);
            }
        };

        int lastNumIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                addMode(nums[lastNumIndex]);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = nums.size() - lastNumIndex;
        ans = max(ans, (int)nums.size() - lastNumIndex);
        addMode(nums[lastNumIndex]);

        auto leftBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            return left;
        };

        for (int mode : modes) {
            int l = leftBound(mode - k);
            int r = rightBound(mode + k);

            int tempAns;
            if (numCount.count(mode)) {
                tempAns = min(r - l + 1, numCount[mode] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }
            ans = max(ans, tempAns);
        }

        return ans;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;

    vector<int> nums1 = {1, 4, 8, 13};
    int k1 = 3, numOperations1 = 2;
    cout << "Output: " << sol.maxFrequency(nums1, k1, numOperations1) << endl; // Expected: 3

    vector<int> nums2 = {5, 5, 5, 5};
    int k2 = 2, numOperations2 = 1;
    cout << "Output: " << sol.maxFrequency(nums2, k2, numOperations2) << endl; // Expected: 4

    return 0;
}
