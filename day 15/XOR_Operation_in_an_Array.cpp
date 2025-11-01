/*
Platform: LeetCode
Problem Name: XOR Operation in an Array
Problem Link: https://leetcode.com/problems/xor-operation-in-an-array/
Problem Code: 1486

Description:
You are given two integers n and start. An array nums is defined as:
    nums[i] = start + 2 * i (where 0 <= i < n).
Return the bitwise XOR of all elements of nums.

Approach:
1. Initialize a variable result = 0.
2. Iterate i from 0 to n-1.
3. For each i, compute nums[i] = start + 2 * i.
4. Apply XOR operation result ^= nums[i].
5. Return result after loop ends.

Time Complexity: O(n)  
Space Complexity: O(1)

Key Insight:
- XOR has the property that a ^ a = 0 and a ^ 0 = a.
- We can build the result incrementally by XORing each element of the constructed sequence.

Example:
Input: n = 5, start = 0
nums = [0, 2, 4, 6, 8]
Output: 8
Explanation: 0 ^ 2 ^ 4 ^ 6 ^ 8 = 8

Additional Notes:
- This is a direct simulation of the array and applying XOR.
- There exists a more optimized mathematical approach, but this solution is straightforward and efficient enough.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result ^= start + 2 * i; // XOR with each element
        }
        return result;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;
    cout << sol.xorOperation(5, 0) << endl; // Expected output: 8
    cout << sol.xorOperation(4, 3) << endl; // Expected output: 8
    cout << sol.xorOperation(1, 7) << endl; // Expected output: 7
    cout << sol.xorOperation(10, 5) << endl; // Expected output: 2
    return 0;
}
