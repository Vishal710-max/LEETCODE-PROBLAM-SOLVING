/*
Platform: LeetCode
Problem Name: 3346. Maximum Frequency of an Element After Performing Operations I
Problem Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
Problem Code: 3346

Description:
You are given an integer array `nums` and two integers `k` and `numOperations`.
You must perform an operation `numOperations` times on `nums`, where in each operation you:
  - Select an index `i` that was not selected before.
  - Add an integer in the range [-k, k] to nums[i].

Your goal is to maximize the frequency of any element in the array after performing these operations.
Return the maximum possible frequency.

Example 1:
Input: nums = [1, 4, 5], k = 1, numOperations = 2
Output: 2
Explanation:
- Add 0 to nums[1] → [1, 4, 5]
- Add -1 to nums[2] → [1, 4, 4]
Maximum frequency = 2

Example 2:
Input: nums = [5, 11, 20, 20], k = 5, numOperations = 1
Output: 2
Explanation:
- Add 0 to nums[1] → [5, 11, 20, 20]
Maximum frequency = 2

Constraints:
1 <= nums.length <= 1e5
1 <= nums[i] <= 1e5
0 <= k <= 1e5
0 <= numOperations <= nums.length

Approach:
1. Sort the array for efficient range-based calculations.
2. Count the frequency of each unique number.
3. For each possible integer in the range [nums.front(), nums.back()],
   - Use binary search (leftBound and rightBound) to find how many elements can be converted 
     into a target value within the range [target - k, target + k].
4. If the target value already exists, add its count and check if additional conversions 
   (up to `numOperations`) can increase the frequency.
5. Keep track of the maximum achievable frequency.

Time Complexity: O(N log N + R log N)
  - Sorting takes O(N log N)
  - For each possible target value R (range between min and max nums), binary searches take O(log N)
Space Complexity: O(N)
  - For storing frequency map and helper computations

Key Insight:
Any number can be adjusted within the range [num - k, num + k].
By finding overlapping ranges and counting how many elements can fall into a single target value,
we can compute the maximum possible frequency after performing allowed operations.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> numCount;

        // Step 1: Count frequencies of each unique number
        int lastNumIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[lastNumIndex]) {
                numCount[nums[lastNumIndex]] = i - lastNumIndex;
                ans = max(ans, i - lastNumIndex);
                lastNumIndex = i;
            }
        }

        numCount[nums[lastNumIndex]] = n - lastNumIndex;
        ans = max(ans, n - lastNumIndex);

        // Step 2: Binary search helpers
        auto leftBound = [&](int value) {
            int left = 0, right = n - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] < value)
                    left = mid + 1;
                else
                    right = mid;
            }
            return left;
        };

        auto rightBound = [&](int value) {
            int left = 0, right = n - 1;
            while (left < right) {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > value)
                    right = mid - 1;
                else
                    left = mid;
            }
            return left;
        };

        // Step 3: Iterate through each possible target value
        for (int target = nums.front(); target <= nums.back(); ++target) {
            int l = leftBound(target - k);
            int r = rightBound(target + k);

            int tempAns;
            if (numCount.count(target)) {
                tempAns = min(r - l + 1, numCount[target] + numOperations);
            } else {
                tempAns = min(r - l + 1, numOperations);
            }

            ans = max(ans, tempAns);
        }

        return ans;
    }
};

// ---------- Driver Code ----------
int main() {
    Solution sol;

    vector<int> nums1 = {1, 4, 5};
    int k1 = 1, numOps1 = 2;
    cout << "Example 1 Output: " << sol.maxFrequency(nums1, k1, numOps1) << endl;

    vector<int> nums2 = {5, 11, 20, 20};
    int k2 = 5, numOps2 = 1;
    cout << "Example 2 Output: " << sol.maxFrequency(nums2, k2, numOps2) << endl;

    vector<int> nums3 = {1, 90};
    int k3 = 76, numOps3 = 1;
    cout << "Example 3 Output: " << sol.maxFrequency(nums3, k3, numOps3) << endl;

    return 0;
}

/*
Expected Output:
Example 1 Output: 2
Example 2 Output: 2
Example 3 Output: 1
*/
