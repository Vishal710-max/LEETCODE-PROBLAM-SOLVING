/*
Platform: LeetCode
Problem Name: Single Number II
Problem Link: https://leetcode.com/problems/single-number-ii/
Problem Code: 137

Description:
Given an integer array nums where every element appears three times except for one, which appears exactly once.
Find the single element and return it.

You must implement a solution with linear runtime complexity (O(n)) and use only constant extra space (O(1)).

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each element in nums appears exactly three times except for one element which appears once.

Approach:
We use bit manipulation with two integer variables `ones` and `twos` to simulate bitwise counting (mod 3) for each bit position.
- `ones` keeps track of bits that have appeared once.
- `twos` keeps track of bits that have appeared twice.
When a bit appears the third time, it is cleared from both `ones` and `twos`.

Algorithm Steps:
1. Initialize two integers: ones = 0, twos = 0.
2. For each number `num` in nums:
   a. Add bits that appear twice: twos |= ones & num
   b. Toggle bits in `ones` using XOR: ones ^= num
   c. Find bits that appeared three times: threes = ones & twos
   d. Clear bits that appeared three times:
      ones &= ~threes
      twos &= ~threes
3. After processing all numbers, `ones` contains the single unique number.

Time Complexity: O(n)
Space Complexity: O(1)

Key Insight:
Each bit position can be represented as a state machine (0 → 1 → 2 → 0) that cycles every 3 occurrences.
Using two bitmasks (`ones`, `twos`), we simulate this mod-3 counting efficiently across all bits simultaneously.

Example:
nums = [2, 2, 3, 2]
Binary forms:
2 → 010
2 → 010
3 → 011
2 → 010
After bitmask operations, result = 011 (binary) = 3

*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            // Step 1: Add bits to 'twos' that are already in 'ones' and also in current num
            twos |= ones & num;

            // Step 2: XOR current num with 'ones' to track bits appearing once
            ones ^= num;

            // Step 3: Identify bits that appeared three times
            int threes = ones & twos;

            // Step 4: Remove bits that appeared three times
            ones &= ~threes;
            twos &= ~threes;
        }

        // 'ones' now holds the number that appeared only once
        return ones;
    }
};

// Example Test
/*
#include <iostream>
int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 2};
    cout << s.singleNumber(nums); // Output: 3
    return 0;
}
*/
