/*
Platform: LeetCode
Problem Name: Check if All Digits are Equal After Repeated Transformation
Problem Link: https://leetcode.com/problems/check-if-all-digits-are-equal-after-repeated-transformation/
Problem Code: (Not Applicable)

Description:
You are given a string `s` consisting of digits ('0' to '9').
In one operation, you can transform `s` into a new string `t` such that:
    - t[i] = ( (s[i] - '0') + (s[i+1] - '0') ) % 10
You continue performing this operation repeatedly until the string length becomes 2.
The task is to determine whether the final two digits in the resulting string are equal.

If both digits are equal, return `true`; otherwise, return `false`.

Approach:
1. While the string length is greater than 2:
   - Create a new string `next` which will store the pairwise sum modulo 10 of adjacent digits.
   - For each pair of consecutive digits in `s`:
        sum = ((s[i] - '0') + (s[i + 1] - '0')) % 10
        Append `sum` to the new string.
   - Replace `s` with `next` and repeat until the string length is 2.
2. After the loop, compare the last two characters in `s`:
   - If they are equal, return `true`.
   - Otherwise, return `false`.

Time Complexity: O(n²)
- Each iteration reduces the string length by 1, and we process up to O(n) pairs each time.

Space Complexity: O(n)
- We create a new string of length n-1 at each iteration.

Key Insight:
The process mimics a reduction operation on adjacent digits where the modulo 10 keeps the sum single-digit.
The pattern stabilizes quickly, and the problem boils down to checking if the final two digits are equal.

Example:
Input: s = "1234"
Step 1: (1+2)%10=3, (2+3)%10=5, (3+4)%10=7 → "357"
Step 2: (3+5)%10=8, (5+7)%10=2 → "82"
Final check: '8' != '2' → false

Output: false

Additional Notes:
- This problem demonstrates iterative digit transformation with modulo arithmetic.
- Similar problems can appear in digit reduction, checksum, or encoding contexts.
*/

#include <iostream>
#include <string>
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

// ---------------- Driver Code / Test Cases ----------------
int main() {
    Solution sol;

    string test1 = "1234";
    cout << "Input: " << test1 << " → Output: " 
         << (sol.hasSameDigits(test1) ? "true" : "false") << endl;

    string test2 = "5678";
    cout << "Input: " << test2 << " → Output: " 
         << (sol.hasSameDigits(test2) ? "true" : "false") << endl;

    string test3 = "999";
    cout << "Input: " << test3 << " → Output: " 
         << (sol.hasSameDigits(test3) ? "true" : "false") << endl;

    string test4 = "112";
    cout << "Input: " << test4 << " → Output: " 
         << (sol.hasSameDigits(test4) ? "true" : "false") << endl;

    return 0;
}
