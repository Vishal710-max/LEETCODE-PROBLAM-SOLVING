/*
LeetCode Problem: 217. Contains Duplicate
Problem Link: https://leetcode.com/problems/contains-duplicate/

Description:
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Approach:
1. Sorting: First, sort the array. This brings any duplicate values next to each other.
2. Linear Scan: Iterate through the sorted array starting from the second element.
   - Compare each element with its previous element.
   - If any two consecutive elements are the same, return true.
3. If no duplicates are found after the scan, return false.

Time Complexity: O(n log n) due to the sorting step, where n is the number of elements in the array.
Space Complexity: O(1) (if we ignore the space used by the sort algorithm itself, which is O(log n) for in-place sorting in C++).

Key Insight:
After sorting, duplicates become adjacent, making them easy to detect with a single pass.

Example:
Input: nums = [1,2,3,1]
Output: true
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the array to group duplicates together
        sort(nums.begin(), nums.end());
        
        // Check adjacent elements for duplicates
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Array with duplicates
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test case 1: [1,2,3,1] -> " << (solution.containsDuplicate(nums1) ? "true" : "false") << endl;
    
    // Test case 2: Array without duplicates
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test case 2: [1,2,3,4] -> " << (solution.containsDuplicate(nums2) ? "true" : "false") << endl;
    
    // Test case 3: Empty array
    vector<int> nums3 = {};
    cout << "Test case 3: [] -> " << (solution.containsDuplicate(nums3) ? "true" : "false") << endl;
    
    // Test case 4: Large array with duplicates
    vector<int> nums4 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test case 4: [1,1,1,3,3,4,3,2,4,2] -> " << (solution.containsDuplicate(nums4) ? "true" : "false") << endl;
    
    return 0;
}

/*
Test case 1: [1,2,3,1] -> true
Test case 2: [1,2,3,4] -> false
Test case 3: [] -> false
Test case 4: [1,1,1,3,3,4,3,2,4,2] -> true
*/