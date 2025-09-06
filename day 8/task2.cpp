/*
Platform: LeetCode
Problem Name: Fruit Into Baskets
Problem Link: https://leetcode.com/problems/fruit-into-baskets/
Problem Code: 904

Description:
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the i-th tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules:
- You only have two baskets, and each basket can only hold a single type of fruit.
- Starting from any tree, you must pick exactly one fruit from every tree (including the start tree) while moving to the right.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Approach:
1. Use a sliding window technique with two pointers (left and right)
2. Maintain an unordered_map to track frequency of fruit types in current window
3. Expand the window by moving the right pointer
4. When the window contains more than 2 distinct fruit types, shrink from the left
5. Remove fruits from the map when their count reaches zero
6. Track the maximum valid window size throughout the process

Time Complexity: O(n) - Each element is processed at most twice (added once, removed once)
Space Complexity: O(1) - The map never contains more than 3 entries

Key Insight:
The problem reduces to finding the longest contiguous subarray with at most 2 distinct values. The sliding window approach efficiently maintains a valid window while exploring all possible subarrays.

Example:
Input: fruits = [1,2,1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,1,2,2] or [1,2,2,2] which contain only two types of fruits.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> check;  // Map to track frequency of fruit types
        int n = fruits.size();
        int maxfruit = 0;
        int left = 0;
        
        for (int i = 0; i < n; i++) {
            check[fruits[i]]++;  // Add current fruit to frequency map
            
            // Shrink window from left if more than 2 fruit types
            while (check.size() > 2) {
                check[fruits[left]]--;
                if (check[fruits[left]] == 0) {
                    check.erase(fruits[left]);
                }
                left++;
            }
            
            // Update maximum valid window size
            maxfruit = max(maxfruit, i - left + 1);
        }
        
        return maxfruit;
    }
};

/*
Test Cases:
Example 1:
Input: [1,2,1]
Output: 3

Example 2:
Input: [0,1,2,2]
Output: 3

Example 3:
Input: [1,2,3,2,2]
Output: 4

Example 4:
Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
*/