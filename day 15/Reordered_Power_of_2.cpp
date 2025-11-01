/*
Platform: LeetCode
Problem Name: Reordered Power of 2
Problem Link: https://leetcode.com/problems/reordered-power-of-2/
Problem Code: 869

Description:
You are given an integer n. 
We want to check if the digits of n can be rearranged (reordered) to form a power of two.
Return true if it is possible, otherwise return false.

Approach:
1. Convert n into a string and sort its digits. This acts as a unique "signature".
2. For every power of 2 in the range [2^0, 2^31], generate its string representation.
3. Sort the digits of each power of 2 and compare it with the sorted digits of n.
4. If any match is found, return true.
5. If no match is found, return false.

Time Complexity: O(32 * k log k),  
where k is the maximum number of digits (~10). Effectively constant time.  

Space Complexity: O(k) for storing and sorting the digit strings.  

Key Insight:
- The order of digits doesn’t matter, only their frequency.  
- Sorting provides a simple way to compare digit frequency signatures.  

Example:
Input: n = 128  
Sorted(n) = "128"  
2^7 = 128 → Sorted = "128"  
Output: true  

Input: n = 10  
Sorted(n) = "01"  
No power of 2 has digits "01".  
Output: false  

Additional Notes:
- An alternative approach is to use frequency arrays instead of sorting, which is slightly faster. 
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        for (int i = 0; i < 32; i++) { // 2^0 to 2^31
            string power = to_string(1 << i);
            sort(power.begin(), power.end());
            if (power == s) {
                return true;
            }
        }
        return false;
    }
};

// Test Cases / Driver Code
int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.reorderedPowerOf2(1) << endl;    // true (2^0 = 1)
    cout << sol.reorderedPowerOf2(10) << endl;   // false
    cout << sol.reorderedPowerOf2(128) << endl;  // true (2^7 = 128)
    cout << sol.reorderedPowerOf2(821) << endl;  // true (reorder to 128)
    cout << sol.reorderedPowerOf2(46) << endl;   // true (reorder to 64 = 2^6)
    return 0;
}
