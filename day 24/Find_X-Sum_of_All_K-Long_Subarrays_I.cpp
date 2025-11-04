/*
Platform: LeetCode
Problem Name: Find X-Sum of All K-Long Subarrays I
Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
Problem Code: 3318

Description:
You are given an integer array nums of length n, and two integers k and x.

The x-sum of an array is defined as follows:
1. Count the occurrences of all elements in the array.
2. Keep only the top x most frequent elements.
   - If two elements have the same frequency, the one with the higher value is considered more frequent.
3. The x-sum is the sum of all occurrences of those top x elements.

Return an integer array answer of length n - k + 1, where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

Example:
Input:  nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
Output: [6,10,12]

Explanation:
- Subarray [1,1,2,2,3,4] → Top 2 frequent: 1 and 2 → x-sum = 1+1+2+2 = 6
- Subarray [1,2,2,3,4,2] → Top 2 frequent: 2 and 4 → x-sum = 2+2+2+4 = 10
- Subarray [2,2,3,4,2,3] → Top 2 frequent: 2 and 3 → x-sum = 2+2+2+3+3 = 12

Approach:
1. For each subarray of length k:
   - Count the frequency of each element using a hash map.
   - Sort elements by frequency (descending), and then by value (descending).
   - Keep top x elements and compute their total contribution to the sum.
2. Append each computed sum to the result array.

Time Complexity: O(n * k * log k)
  - For each window, counting takes O(k), sorting frequencies takes O(k log k).
Space Complexity: O(k)
  - For storing frequency counts.

Key Insight:
- Since n ≤ 50, a brute-force approach is efficient enough.
- Sorting by frequency and value ensures correct priority of elements.

Additional Notes:
- If there are fewer than x distinct elements, we sum all elements in the subarray.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i <= n - k; ++i) {
            // Frequency map for current window
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }

            // Convert to vector for sorting
            vector<pair<int, int>> freqVec;
            for (auto& [num, count] : freq) {
                freqVec.push_back({count, num});
            }

            // Sort: higher frequency first, then higher value
            sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second > b.second;
                return a.first > b.first;
            });

            // Compute x-sum
            int sum = 0, cnt = 0;
            for (auto& [count, num] : freqVec) {
                if (cnt == x) break;
                sum += count * num;
                cnt++;
            }

            result.push_back(sum);
        }

        return result;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;

    vector<int> nums1 = {1, 1, 2, 2, 3, 4, 2, 3};
    int k1 = 6, x1 = 2;
    vector<int> res1 = sol.findXSum(nums1, k1, x1);
    cout << "Output 1: ";
    for (int v : res1) cout << v << " ";
    cout << endl; // Expected: 6 10 12

    vector<int> nums2 = {3, 8, 7, 8, 7, 5};
    int k2 = 2, x2 = 2;
    vector<int> res2 = sol.findXSum(nums2, k2, x2);
    cout << "Output 2: ";
    for (int v : res2) cout << v << " ";
    cout << endl; // Expected: 11 15 15 15 12

    return 0;
}
