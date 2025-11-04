/*
Platform: LeetCode
Problem Name: 3461. Check If Digits Are Equal in String After Operations I
Problem Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
Problem Code: 3461

Description:
You are given a string s consisting only of digits (0–9).
You need to perform the following operation repeatedly until the string has exactly two digits:

Operation:
- For each pair of consecutive digits in s (starting from the first digit),
  calculate a new digit as (sum of the two digits) % 10.
- Replace s with the sequence of newly calculated digits.

After repeating the process until two digits remain, 
return true if both digits are equal; otherwise, return false.

Approach:
1. Continue performing the transformation while the string length > 2.
2. For each iteration:
   - Compute the sum of each consecutive pair modulo 10.
   - Build a new string of these results.
3. Once only two digits remain, compare them:
   - If both are the same, return true; otherwise, false.

Time Complexity: O(n²)
- Each iteration reduces the string length by 1.
- Total of (n−1) + (n−2) + ... + 2 = O(n²) operations.

Space Complexity: O(n)
- Uses a temporary string for intermediate results.

Key Insight:
The process mimics a “digit-reduction triangle” — 
each layer is formed by summing adjacent digits modulo 10 
until only two digits remain.

Example:
Input:
s = "3902"

Steps:
"3902"
→ (3+9)%10=2, (9+0)%10=9, (0+2)%10=2 → "292"
→ (2+9)%10=1, (9+2)%10=1 → "11"

Since both digits are equal, output = true

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string next = "";
            for (int i = 0; i < s.size() - 1; ++i) {
                int sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
                next.push_back(sum + '0');
            }
            s = next;
        }
        // Check if both digits are equal
        return s[0] == s[1];
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;

    string s1 = "3902";
    cout << "Input: " << s1 << " → Output: " 
         << (sol.hasSameDigits(s1) ? "true" : "false") << endl; 
    // Expected: true

    string s2 = "34789";
    cout << "Input: " << s2 << " → Output: " 
         << (sol.hasSameDigits(s2) ? "true" : "false") << endl;
    // Expected: false

    return 0;
}
