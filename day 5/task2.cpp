/*
LeetCode Problem: 219. Contains Duplicate II
Problem Link: https://leetcode.com/problems/contains-duplicate-ii/

Description:
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that:
- nums[i] == nums[j]
- abs(i - j) <= k

Approach:
1. Hash Map: Use an unordered_map to store the most recent index of each number.
2. Iterate through the array:
   - For each number, check if it has been seen before (exists in the map).
   - If it exists, check if the absolute difference between the current index and the stored index is <= k.
   - If yes, return true.
   - Otherwise, update the map with the current index for that number.
3. If no such pair is found after iterating, return false.

Time Complexity: O(n), where n is the number of elements in the array.
Space Complexity: O(n), due to the hash map storing up to n elements.

Key Insight:
By storing the last occurrence of each number, we can efficiently check if the current index and the last index are within k distance.

Example:
Input: nums = [1,2,3,1], k = 3
Output: true
Explanation: The element 1 at index 0 and index 3 satisfies the conditions.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // key: number, value: latest index
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // Check if the number exists in the map and if the index difference is <= k
            if (map.find(num) != map.end() && i - map[num] <= k) {
                return true;
            }
            // Update the map with the current index for the number
            map[num] = i;
        }
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Example from the problem
    vector<int> nums1 = {1, 2, 3, 1};
    int k1 = 3;
    cout << "Test case 1: nums = [1,2,3,1], k = 3 -> " 
         << (solution.containsNearbyDuplicate(nums1, k1) ? "true" : "false") << endl;
    
    // Test case 2: No duplicates within k distance
    vector<int> nums2 = {1, 2, 3, 1, 2, 3};
    int k2 = 2;
    cout << "Test case 2: nums = [1,2,3,1,2,3], k = 2 -> " 
         << (solution.containsNearbyDuplicate(nums2, k2) ? "true" : "false") << endl;
    
    // Test case 3: Duplicates exactly at k distance
    vector<int> nums3 = {1, 0, 1, 1};
    int k3 = 1;
    cout << "Test case 3: nums = [1,0,1,1], k = 1 -> " 
         << (solution.containsNearbyDuplicate(nums3, k3) ? "true" : "false") << endl;
    
    // Test case 4: Empty array
    vector<int> nums4 = {};
    int k4 = 0;
    cout << "Test case 4: nums = [], k = 0 -> " 
         << (solution.containsNearbyDuplicate(nums4, k4) ? "true" : "false") << endl;
    
    return 0;
}

/*
Test case 1: nums = [1,2,3,1], k = 3 -> true
Test case 2: nums = [1,2,3,1,2,3], k = 2 -> false
Test case 3: nums = [1,0,1,1], k = 1 -> true
Test case 4: nums = [], k = 0 -> false
*/