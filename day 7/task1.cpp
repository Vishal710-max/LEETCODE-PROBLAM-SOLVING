#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Platform: LeetCode
Problem Name: Alternate Digit Sum
Problem Link: https://leetcode.com/problems/alternate-digit-sum/
Problem Code: 2544

Description:
You are given a positive integer n. Each digit of n is alternated between adding and subtracting starting from the first digit (which is added).
Return the sum of the digits with their respective signs.

Approach:
1. Extract each digit of the number and store them in a vector in reverse order (because digits are extracted from least significant to most).
2. Reverse the vector to get the digits from most significant to least.
3. Iterate through the digits: add digits at even indices (0-indexed) and subtract digits at odd indices.

Time Complexity: O(d), where d is the number of digits in n.
Space Complexity: O(d), to store the digits.

Key Insight:
The sign alternates starting with positive for the first digit. By storing the digits in order and then iterating with index checks, we can apply the correct sign.

Example:
Input: n = 521
Output: 4
Explanation: 
- Digits: [5, 2, 1]
- Alternate sum: +5 -2 +1 = 4.

Additional Notes:
This approach is straightforward and leverages vector reversal to process digits in the correct order.
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digit;
        int sum = 0;
        while (n > 0){
            digit.push_back(n % 10);
            n /= 10;
        }
        reverse(digit.begin(), digit.end());
        for (int i = 0; i < digit.size(); i++){
            if (i % 2 == 0){
                sum += digit[i];
            } else {
                sum -= digit[i];
            }
        }
        return sum;
    }
};

// Driver code for testing
int main() {
    Solution sol;
    
    // Test cases
    int test_cases[] = {521, 111, 886996, 10, 1};
    int expected[] = {4, 1, 16, 1, 1};
    
    cout << "Testing Alternate Digit Sum Solution:" << endl;
    cout << "=====================================" << endl;
    
    for (int i = 0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++) {
        int result = sol.alternateDigitSum(test_cases[i]);
        cout << "Input: " << test_cases[i] << " -> Output: " << result;
        cout << " (Expected: " << expected[i] << ")";
        cout << " -> " << (result == expected[i] ? "✓ PASS" : "✗ FAIL") << endl;
    }
    
    return 0;
}