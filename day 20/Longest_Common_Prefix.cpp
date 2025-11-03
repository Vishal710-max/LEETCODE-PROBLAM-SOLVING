/*
Platform: LeetCode
Problem Name: 14. Longest Common Prefix
Problem Link: https://leetcode.com/problems/longest-common-prefix/
Problem Code: 14

Description:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Approach:
1. Initialize the first string as the initial prefix.
2. Iterate through each string in the array starting from the second one.
3. For each string, check if it starts with the current prefix.
   - If not, reduce the prefix length by one character from the end until it matches.
   - If prefix becomes empty, return "" immediately.
4. After processing all strings, the remaining prefix is the longest common prefix.

Time Complexity: O(S)
    - Where S is the total number of characters in all strings.
Space Complexity: O(1)
    - Only a few auxiliary variables are used.

Key Insight:
The longest common prefix must be a prefix of the first string.  
So, we can gradually trim it down until it fits all others.

Example:
Input: ["interview", "internet", "internal", "interval"]
Step-by-step:
- Start with prefix = "interview"
- Compare with "internet" → common part: "inter"
- Compare with "internal" → "inter"
- Compare with "interval" → "inter"
Output: "inter"
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << "Input: [flower, flow, flight]" << endl;
    cout << "Output: " << sol.longestCommonPrefix(strs1) << endl << endl;

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << "Input: [dog, racecar, car]" << endl;
    cout << "Output: " << sol.longestCommonPrefix(strs2) << endl << endl;

    vector<string> strs3 = {"interview", "internet", "internal", "interval"};
    cout << "Input: [interview, internet, internal, interval]" << endl;
    cout << "Output: " << sol.longestCommonPrefix(strs3) << endl;

    return 0;
}
