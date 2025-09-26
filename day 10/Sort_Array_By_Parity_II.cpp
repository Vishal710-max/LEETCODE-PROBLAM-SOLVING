/*
Platform: LeetCode
Problem Name: Sort Array By Parity II
Problem Link: https://leetcode.com/problems/sort-array-by-parity-ii/
Problem Code: 922

Description:
Given an array of integers nums, half of the integers in nums are odd, and the other half are even.
Sort the array so that whenever the index is even, the element at that index is even, and whenever 
the index is odd, the element at that index is odd. Return any answer array that satisfies this condition.

Approach:
1. Create a result array of the same size as input
2. Use two pointers: evenIndex (starting at 0) for even positions, oddIndex (starting at 1) for odd positions
3. Iterate through each number in the input array
4. If the number is even, place it at evenIndex and increment evenIndex by 2
5. If the number is odd, place it at oddIndex and increment oddIndex by 2
6. This ensures even numbers go to even indices and odd numbers go to odd indices

Time Complexity: O(n) - Single pass through the array
Space Complexity: O(n) - Additional array of size n is used

Key Insight:
Since we know exactly half the numbers are even and half are odd, we can use two separate pointers 
to place even and odd numbers in their correct positions simultaneously without needing to sort the entire array.

Example:
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: 
- Index 0 (even): 4 (even) ✓
- Index 1 (odd): 5 (odd) ✓
- Index 2 (even): 2 (even) ✓
- Index 3 (odd): 7 (odd) ✓
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int evenIndex = 0;
        int oddIndex = 1;
        
        for (int num : nums) {
            if (num % 2 == 0) {
                result[evenIndex] = num;
                evenIndex += 2;
            } else {
                result[oddIndex] = num;
                oddIndex += 2;
            }
        }
        return result;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// Helper function to validate the result
bool isValidResult(const vector<int>& result) {
    for (int i = 0; i < result.size(); i++) {
        if (i % 2 == 0 && result[i] % 2 != 0) {
            return false;
        }
        if (i % 2 == 1 && result[i] % 2 != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {4, 2, 5, 7};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    vector<int> result1 = solution.sortArrayByParityII(nums1);
    cout << "Output: ";
    printVector(result1);
    cout << "Valid: " << (isValidResult(result1) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test Case 2
    vector<int> nums2 = {2, 3};
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    vector<int> result2 = solution.sortArrayByParityII(nums2);
    cout << "Output: ";
    printVector(result2);
    cout << "Valid: " << (isValidResult(result2) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6};
    cout << "Test Case 3:" << endl;
    cout << "Input: ";
    printVector(nums3);
    vector<int> result3 = solution.sortArrayByParityII(nums3);
    cout << "Output: ";
    printVector(result3);
    cout << "Valid: " << (isValidResult(result3) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Test Case 4
    vector<int> nums4 = {648, 831, 560, 986, 192, 424, 997, 829, 897, 843};
    cout << "Test Case 4:" << endl;
    cout << "Input: ";
    printVector(nums4);
    vector<int> result4 = solution.sortArrayByParityII(nums4);
    cout << "Output: ";
    printVector(result4);
    cout << "Valid: " << (isValidResult(result4) ? "Yes" : "No") << endl;
    
    return 0;
}


Expected Output:
Test Case 1:
Input: [4, 2, 5, 7]
Output: [4, 5, 2, 7]
Valid: Yes

Test Case 2:
Input: [2, 3]
Output: [2, 3]
Valid: Yes

Test Case 3:
Input: [1, 2, 3, 4, 5, 6]
Output: [2, 1, 4, 3, 6, 5] (or similar valid arrangement)
Valid: Yes

Test Case 4:
Input: [648, 831, 560, 986, 192, 424, 997, 829, 897, 843]
Output: [648, 831, 560, 997, 192, 829, 986, 897, 424, 843] (or similar)
Valid: Yes
