#include <iostream>
using namespace std;

/*
Problem: 342. Power of Four
----------------------------
Given an integer n, return true if it is a power of four. Otherwise, return false.

Definition:
-----------
An integer n is a power of four if there exists an integer x such that:
    n == 4^x

Example 1:
----------
Input:  n = 16
Output: true
Explanation: 4^2 = 16

Example 2:
----------
Input:  n = 5
Output: false

Constraints:
------------
- -2^31 <= n <= 2^31 - 1

-------------------------------------------------------------------
Approach (Math Trick + Power of Two):
-------------------------------------
1. A number is a power of four if:
    - It is greater than 0.
    - It is also a power of two.
    - Additionally, (n - 1) must be divisible by 3.
      (Because 4^k - 1 is always divisible by 3).

2. Steps:
    - Check if n > 0.
    - Verify n is a power of two using (n & (n - 1)) == 0.
    - Check divisibility: (n - 1) % 3 == 0.

3. Example:
    n = 16
    - n > 0 ✅
    - n & (n - 1) == 0 → 16 & 15 = 0 ✅ (power of two)
    - (n - 1) % 3 = 15 % 3 = 0 ✅
    => true (16 is a power of four)

4. Time Complexity: O(1)
5. Space Complexity: O(1)
-------------------------------------------------------------------
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Check: Positive number, power of two, and (n - 1) divisible by 3
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

int main() {
    Solution obj;

    // Test cases
    int test1 = 16;
    int test2 = 5;
    int test3 = 1;

    cout << "Input: " << test1 << " -> Output: " << (obj.isPowerOfFour(test1) ? "true" : "false") << endl;
    cout << "Input: " << test2 << " -> Output: " << (obj.isPowerOfFour(test2) ? "true" : "false") << endl;
    cout << "Input: " << test3 << " -> Output: " << (obj.isPowerOfFour(test3) ? "true" : "false") << endl;

    return 0;
}

// Expected Output =>
// Input: 16 -> Output: true
// Input: 5  -> Output: false
// Input: 1  -> Output: true
