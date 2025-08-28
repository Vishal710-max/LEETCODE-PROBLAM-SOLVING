/*
Platform: LeetCode
Problem Name: Special Array I
Problem Link: https://leetcode.com/problems/special-array-i/
Problem Code: 3151

Description:
An array is considered special if every pair of its consecutive elements 
contains two numbers with different parity (one even and one odd).
Given an integer array nums, return true if the array is special, otherwise return false.

Approach:
1. Iterate through the array starting from the second element
2. For each element, check if it has the same parity as the previous element
3. If any consecutive elements have the same parity, return false immediately
4. If all consecutive pairs have different parity, return true

Time Complexity: O(n) - Single pass through the array
Space Complexity: O(1) - Constant extra space used

Key Insight:
The problem reduces to checking that no two consecutive elements share the same parity.
We can use modulo operation to determine parity and compare adjacent elements.

Example:
Input: nums = [1, 2, 3, 4]
Output: true
Explanation: 
- (1, 2): odd and even → different parity ✓
- (2, 3): even and odd → different parity ✓
- (3, 4): odd and even → different parity ✓

Note: A single element array is always special as there are no consecutive pairs to compare.
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Single element array is always special
        if (nums.size() <= 1) {
            return true;
        }
        
        // Check each consecutive pair for same parity
        for (int i = 1; i < nums.size(); i++) {
            // If both even or both odd, array is not special
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};

/*
Test Cases:
Test case 1: [1,2,3,4] → true
Test case 2: [2,4,6,8] → false (all even)
Test case 3: [1,3,5,7] → false (all odd)
Test case 4: [5] → true (single element)
Test case 5: [1,2,4,3] → false (2 and 4 are both even)
*/

#include <iostream>
using namespace std;

int main() {
    Solution solution;
    
    vector<int> test1 = {1, 2, 3, 4};
    cout << "Test 1: " << (solution.isArraySpecial(test1) ? "true" : "false") << endl;
    
    vector<int> test2 = {2, 4, 6, 8};
    cout << "Test 2: " << (solution.isArraySpecial(test2) ? "true" : "false") << endl;
    
    vector<int> test3 = {1, 3, 5, 7};
    cout << "Test 3: " << (solution.isArraySpecial(test3) ? "true" : "false") << endl;
    
    vector<int> test4 = {5};
    cout << "Test 4: " << (solution.isArraySpecial(test4) ? "true" : "false") << endl;
    
    vector<int> test5 = {1, 2, 4, 3};
    cout << "Test 5: " << (solution.isArraySpecial(test5) ? "true" : "false") << endl;
    
    return 0;
}

/*
Expected Output:
Test 1: true
Test 2: false
Test 3: false
Test 4: true
Test 5: false
*/