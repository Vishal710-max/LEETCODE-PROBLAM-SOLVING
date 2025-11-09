/*
Platform: LeetCode
Problem Name: Next Beautiful Number
Problem Link: https://leetcode.com/problems/next-beautiful-number/
Problem Code: (Not Applicable)

Description:
A number is called *beautiful* if the frequency of every digit in the number 
equals the digit itself.

For example:
- 22 is beautiful because the digit 2 appears exactly twice.
- 1333 is beautiful because the digit 1 appears once and 3 appears three times.
- 23 is NOT beautiful because 2 appears once and 3 appears once.

Given an integer `n`, find and return the smallest *beautiful number* that is strictly greater than `n`.

Constraints:
- 0 <= n <= 10^6

Approach:
1. Each digit from 1–9 can appear exactly `d` times in a beautiful number.
   For example:
   - Digit 1 → can appear once.
   - Digit 2 → can appear twice.
   - Digit 3 → can appear thrice.
   - and so on...

2. For each possible combination (subset) of digits {1..9}, form a string `s` that repeats each chosen digit `d` exactly `d` times.
   - Example subset {1, 2} → string = "122"
   - Example subset {3} → string = "333"

3. For each generated string, compute all **unique permutations** of digits.
   - Convert each permutation to a number and store it in a set.

4. Finally, among all generated numbers, find the **smallest number greater than `n`**.

Time Complexity: O(9! * 2^9) in worst case (bounded since digits ≤ 9 and number ≤ 1e6)
Space Complexity: O(K), where K is the number of generated beautiful numbers (a few thousand at most)

Key Insight:
Instead of checking each number one by one, pre-generate all possible beautiful numbers (since they are few) 
and pick the smallest one greater than `n`.

Example:
Input: n = 3000  
Possible beautiful numbers > 3000 are [3133, 3311, 3333, 4444, ...]  
Output: 3133

Additional Notes:
- Precomputation of all beautiful numbers is efficient since valid numbers are limited.
- Sorting and permutation generation ensures uniqueness and ordering.
*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        set<long long> results;
        const int MAX_LEN = 7; // Safe upper bound for n <= 1e6

        // Iterate all non-empty subsets of digits 1..9
        for (int mask = 1; mask < (1 << 9); ++mask) {
            string s = "";
            int totalLen = 0;

            // Form string with each chosen digit 'd' repeated 'd' times
            for (int d = 1; d <= 9; ++d) {
                if (mask & (1 << (d - 1))) {
                    totalLen += d;
                    if (totalLen > MAX_LEN) break; // Too long, skip
                    s.append(d, char('0' + d));
                }
            }

            if (totalLen == 0 || totalLen > MAX_LEN) continue;

            // Generate all distinct permutations of s
            sort(s.begin(), s.end());
            do {
                if (s[0] == '0') continue; // Skip invalid leading zero cases
                long long val = stoll(s);
                results.insert(val);
            } while (next_permutation(s.begin(), s.end()));
        }

        // Find the smallest beautiful number greater than n
        for (long long v : results) {
            if (v > n) return (int)v;
        }

        return -1; // Should not occur under valid constraints
    }
};

// ---------------- Driver Code / Test Cases ----------------
int main() {
    Solution sol;

    int test1 = 1;
    cout << "Input: " << test1 << " → Output: " << sol.nextBeautifulNumber(test1) << endl;

    int test2 = 3000;
    cout << "Input: " << test2 << " → Output: " << sol.nextBeautifulNumber(test2) << endl;

    int test3 = 9999;
    cout << "Input: " << test3 << " → Output: " << sol.nextBeautifulNumber(test3) << endl;

    int test4 = 122;
    cout << "Input: " << test4 << " → Output: " << sol.nextBeautifulNumber(test4) << endl;

    return 0;
}
