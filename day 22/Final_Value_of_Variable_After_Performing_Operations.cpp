/*
Platform: LeetCode
Problem Name: 2011. Final Value of Variable After Performing Operations
Problem Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
Problem Code: 2011

Description:
There is a programming language with only one variable X, initialized to 0, 
and four operations: "++X", "X++", "--X", "X--".

Each operation either increments or decrements X by 1.  
Given a list of operations, return the **final value of X** after performing all operations.

Example 1:
Input: operations = ["--X","X++","X++"]
Output: 1
Explanation:
Initially, X = 0
--X → X = -1
X++ → X = 0
X++ → X = 1

Example 2:
Input: operations = ["++X","++X","X++"]
Output: 3

Example 3:
Input: operations = ["X++","++X","--X","X--"]
Output: 0

Approach:
1. Initialize X = 0.
2. Iterate through the list of operations.
3. If the operation contains '+', increment X.
4. If it contains '-', decrement X.
5. Return the final value of X.

Time Complexity: O(n), n = number of operations
Space Complexity: O(1)

Key Insight:
All increment operations contain '+', and all decrement operations contain '-'.
Thus, we can simply check for '+' or '-' in the string.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string op : operations) {
            if (op.find('+') != string::npos)
                X += 1;
            else
                X -= 1;
        }
        return X;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<string> operations1 = {"--X","X++","X++"};
    cout << "Input: [\"--X\",\"X++\",\"X++\"]" << endl;
    cout << "Output: " << sol.finalValueAfterOperations(operations1) << endl << endl;

    vector<string> operations2 = {"++X","++X","X++"};
    cout << "Input: [\"++X\",\"++X\",\"X++\"]" << endl;
    cout << "Output: " << sol.finalValueAfterOperations(operations2) << endl << endl;

    vector<string> operations3 = {"X++","++X","--X","X--"};
    cout << "Input: [\"X++\",\"++X\",\"--X\",\"X--\"]" << endl;
    cout << "Output: " << sol.finalValueAfterOperations(operations3) << endl;

    return 0;
}
