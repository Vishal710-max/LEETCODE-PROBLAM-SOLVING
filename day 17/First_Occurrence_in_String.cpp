/*
Platform: LeetCode
Problem Name: 28. Find the Index of the First Occurrence in a String
Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
Problem Code: 28

Description:
You are given two strings `haystack` and `needle`.
Return the index of the first occurrence of `needle` in `haystack`,
or -1 if `needle` is not part of `haystack`.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" does not occur in "leetcode".

Approach:
1. Let n = length of haystack, m = length of needle.
2. If m > n, return -1 (needle cannot fit in haystack).
3. For each possible starting position i from 0 to n - m:
   - Compare haystack[i + j] with needle[j] for j from 0 to m-1.
   - If all characters match, return i.
4. If no position matches, return -1.

Time Complexity: O(n * m)
   - Each starting position may require checking up to m characters.
Space Complexity: O(1)
   - Only integer variables are used.

Key Insight:
This is a direct brute-force substring search implementation.
It compares all possible starting positions until it finds a match.

Example:
Input: haystack = "hello", needle = "ll"
Output: 2
Explanation: "ll" starts at index 2.

Additional Notes:
This is the basic approach; for optimization, algorithms like KMP (Knuth-Morris-Pratt)
can achieve O(n + m) time complexity.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;  // Found a full match
        }

        return -1;  // Not found
    }
};

int main() {
    Solution sol;

    // Test Case 1
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "Input: haystack = \"" << haystack1 << "\", needle = \"" << needle1 << "\"" << endl;
    cout << "Output: " << sol.strStr(haystack1, needle1) << endl << endl;

    // Test Case 2
    string haystack2 = "leetcode";
    string needle2 = "leeto";
    cout << "Input: haystack = \"" << haystack2 << "\", needle = \"" << needle2 << "\"" << endl;
    cout << "Output: " << sol.strStr(haystack2, needle2) << endl << endl;

    // Test Case 3
    string haystack3 = "hello";
    string needle3 = "ll";
    cout << "Input: haystack = \"" << haystack3 << "\", needle = \"" << needle3 << "\"" << endl;
    cout << "Output: " << sol.strStr(haystack3, needle3) << endl;

    return 0;
}
