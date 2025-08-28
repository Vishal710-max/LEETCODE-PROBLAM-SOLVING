#include <iostream>
using namespace std;

/*
Platform: LeetCode
Problem Name: Add Digits
Problem Link: https://leetcode.com/problems/add-digits/
Problem Code: 258

Description:
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Approach:
The problem can be solved using mathematical insight. The digital root of a number is the value obtained by an iterative process of summing digits until a single-digit number is reached. 
Mathematically, the digital root of a number can be found using modulo 9. Specifically:
- If the number is 0, the digital root is 0.
- If the number is divisible by 9, the digital root is 9.
- Otherwise, the digital root is the remainder when the number is divided by 9.

Time Complexity: O(1)
Space Complexity: O(1)

Key Insight:
The digital root of a number is related to its value modulo 9. This property allows us to compute the result in constant time without any loops.

Example:
Input: num = 38
Output: 2
Explanation: 3 + 8 = 11, then 1 + 1 = 2.

Additional Notes:
This approach leverages the mathematical formula for digital root, which is efficient and avoids iterative digit summing.
*/

class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        return (num % 9 == 0) ? 9 : num % 9;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    
    // Test cases
    int test_cases[] = {38, 0, 9, 123, 999, 10};
    int expected[] = {2, 0, 9, 6, 9, 1};
    
    cout << "Testing Add Digits Solution:" << endl;
    cout << "=============================" << endl;
    
    for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++) {
        int result = sol.addDigits(test_cases[i]);
        cout << "Input: " << test_cases[i] << " -> Output: " << result;
        cout << " (Expected: " << expected[i] << ")";
        cout << " -> " << (result == expected[i] ? "✓ PASS" : "✗ FAIL") << endl;
    }
    
    return 0;
}