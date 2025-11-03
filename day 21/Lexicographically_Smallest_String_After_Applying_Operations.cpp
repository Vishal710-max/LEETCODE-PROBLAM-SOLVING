/*
Platform: LeetCode
Problem Name: 1625. Lexicographically Smallest String After Applying Operations
Problem Link: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
Problem Code: 1625

Description:
You are given a string `s` consisting of digits, and two integers `a` and `b`.

You can perform any number of the following two operations on `s`:
1. Add `a` to all digits at odd indices (0-indexed). The addition wraps around modulo 10.
2. Rotate the string to the right by `b` positions.

Return the **lexicographically smallest string** you can obtain after applying the operations any number of times.

Example 1:
Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: By repeatedly adding and rotating, the smallest string achievable is "2050".

Example 2:
Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: Applying operations results in "24" being the smallest lexicographically.

Approach:
1. Use **Breadth-First Search (BFS)** to explore all possible strings obtainable by operations.
2. Maintain a queue of strings to process and a visited set to avoid cycles.
3. For each string:
   - Apply operation 1: add `a` to all odd indices modulo 10.
   - Apply operation 2: rotate the string right by `b` positions.
4. Track the lexicographically smallest string seen.
5. Continue until all reachable strings are processed.

Time Complexity: O(10^n) in the worst case (all digit combinations),  
   but practical limits are reduced due to repetitions and modulo constraints.
Space Complexity: O(10^n)
   - For the visited set storing strings.

Key Insight:
- BFS ensures that we explore all reachable strings systematically.
- Using a visited set prevents infinite loops caused by repeated operations.

*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string smallest = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            // Update smallest lexicographically
            if (cur < smallest)
                smallest = cur;

            // Operation 1: add a to odd indices
            string addOp = cur;
            for (int i = 1; i < addOp.size(); i += 2) {
                addOp[i] = ((addOp[i] - '0' + a) % 10) + '0';
            }
            if (!visited.count(addOp)) {
                visited.insert(addOp);
                q.push(addOp);
            }

            // Operation 2: rotate by b
            string rotOp = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!visited.count(rotOp)) {
                visited.insert(rotOp);
                q.push(rotOp);
            }
        }

        return smallest;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    string s1 = "5525"; int a1 = 9; int b1 = 2;
    cout << "Input: s = \"5525\", a = 9, b = 2" << endl;
    cout << "Output: " << sol.findLexSmallestString(s1, a1, b1) << endl << endl;

    string s2 = "74"; int a2 = 5; int b2 = 1;
    cout << "Input: s = \"74\", a = 5, b = 1" << endl;
    cout << "Output: " << sol.findLexSmallestString(s2, a2, b2) << endl << endl;

    string s3 = "0011"; int a3 = 4; int b3 = 2;
    cout << "Input: s = \"0011\", a = 4, b = 2" << endl;
    cout << "Output: " << sol.findLexSmallestString(s3, a3, b3) << endl;

    return 0;
}
