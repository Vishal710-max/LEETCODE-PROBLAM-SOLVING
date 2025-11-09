/*
Platform: LeetCode
Problem Name: Calculate Money in Leetcode Bank
Problem Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
Problem Code: (Not Applicable)

Description:
Hercy wants to save money for his future. 
He deposits money in the Leetcode bank every day following a specific pattern:

- On the 1st Monday, he deposits $1.
- Every day of that week, he deposits $1 more than the previous day.
  So, the first week’s deposits are: 1, 2, 3, 4, 5, 6, 7 → total = 28.
- On the 2nd Monday, he deposits $2 (one more than the previous Monday), 
  and again increases by $1 each day that week.
  So, the second week’s deposits are: 2, 3, 4, 5, 6, 7, 8 → total = 35.
- The pattern continues...

Given `n` — the number of days Hercy deposits money — 
return the total amount of money he will have in the bank at the end of the nth day.

Example:
Input: n = 10  
Week 1 → 1+2+3+4+5+6+7 = 28  
Week 2 (3 days) → 8+9+10 = 27  
Total = 28 + 27 = 55  
Output: 55

Approach:
1. Compute how many complete weeks (`weeks = n / 7`) and how many extra days remain (`remaining = n % 7`).
2. Each week forms an arithmetic series:
   - Week 1 total = 28 (1+2+...+7)
   - Week 2 total = 28 + 7 = 35
   - Week 3 total = 28 + 14 = 42, etc.
   - Therefore, total for all full weeks:
     = (weeks * 28) + (sum of first (weeks - 1) integers * 7)
     = weeks * 28 + (weeks * (weeks - 1) / 2) * 7
3. For remaining days, start from (weeks + 1) on Monday and keep adding 1 per day.

Time Complexity: O(1)
Space Complexity: O(1)

Key Insight:
This problem is based on identifying two arithmetic sequences:
- One for the weekly increment.
- One for the extra days after the full weeks.

Example:
Input: n = 20
→ 2 full weeks (2*28 + (2*(2-1)/2)*7 = 63)
→ Remaining 6 days starting from 3 → (3+4+5+6+7+8) = 33
→ Total = 63 + 33 = 96

Output: 96
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int remaining = n % 7;
        
        // Total from full weeks (Arithmetic Series)
        // First week total = 28, increases by 7 each week
        int total = weeks * 28 + (weeks * (weeks - 1) / 2) * 7;
        
        // Remaining days: start from (weeks + 1) dollars on Monday
        for (int i = 0; i < remaining; ++i) {
            total += (weeks + 1) + i;
        }
        
        return total;
    }
};

// ---------------- Driver Code / Test Cases ----------------
int main() {
    Solution sol;

    int test1 = 4;
    cout << "Input: " << test1 << " → Output: " << sol.totalMoney(test1) << endl;

    int test2 = 10;
    cout << "Input: " << test2 << " → Output: " << sol.totalMoney(test2) << endl;

    int test3 = 20;
    cout << "Input: " << test3 << " → Output: " << sol.totalMoney(test3) << endl;

    int test4 = 1000;
    cout << "Input: " << test4 << " → Output: " << sol.totalMoney(test4) << endl;

    return 0;
}
