#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
===========================================================================
🧮 LeetCode Problem: 1636. Sort Array by Increasing Frequency
🔗 Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
💡 Difficulty: Easy
===========================================================================

📘 Problem Statement:
Given an array of integers `nums`, sort the array in **increasing order based on the frequency** of the values.  
If multiple values have the **same frequency**, sort them in **decreasing order**.

Return the sorted array.

-------------------------------------------------------------------------------
🔍 Example 1:
Input:  nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation:
- Frequency: 3 → 1, 1 → 2, 2 → 3
- So sort by frequency ascending, value descending if tie.

🔍 Example 2:
Input:  nums = [2,3,1,3,2]
Output: [1,3,3,2,2]

🔍 Example 3:
Input:  nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]

-------------------------------------------------------------------------------
🧠 Approach:

1️⃣ Count the frequency of each element using `unordered_map<int, int>`.

2️⃣ Convert the map to a `vector<pair<int, int>>` so that it can be sorted.

3️⃣ Sort using a custom comparator:
    - If frequencies are equal, sort by value descending (`a.first > b.first`)
    - Else, sort by frequency ascending (`a.second < b.second`)

4️⃣ Use `insert()` with `p.second` count of `p.first` into the result array.

🕒 Time Complexity: O(n log n) – due to sorting
🛢️ Space Complexity: O(n) – for map and result

===============================================================================
*/



class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
      unordered_map<int,int> freq;
    
    // Count frequencies
    for(int num : nums){
        freq[num]++;
    }
    
    // Sort with custom comparator
    sort(nums.begin(), nums.end(), [&](int a, int b){
        if(freq[a] != freq[b]) return freq[a] < freq[b]; // frequency ascending
        return a > b; // value descending if same frequency
    });
    
    return nums;
    }
};

// 📌 Main function to test the solution
int main() {
    Solution sol;

    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> sorted = sol.frequencySort(nums);

    // 🖨️ Print the sorted array
    cout << "Sorted by frequency: ";
    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}