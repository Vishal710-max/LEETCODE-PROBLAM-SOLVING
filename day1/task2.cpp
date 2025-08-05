#include <iostream>
#include <vector>
using namespace std;

// ✅ Problem Statement:
// Given a non-empty array of integers, where every element appears twice except for one, 
//find the element that appears only once.

// ✅ Approach (Using XOR):
// XOR of two same numbers is 0.

// XOR of any number with 0 is the number itself.

// So, if we XOR all the numbers, duplicates cancel out, and only the single number remains.
// Time complexity: O(n)
// Space complexity: O(1)  


class Solution {
public:
    // Function to find the element that appears only once
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // XOR all elements. Duplicates will cancel each other out.
        for (int i = 0; i < nums.size(); i++) {
            result = result ^ nums[i];  // XOR operation
        }

        return result;  // Return the unique element
    }
};

int main() {
    Solution sol;

    // Sample input where all numbers except one appear twice
    vector<int> nums = {4, 1, 2, 1, 2};

    // Call the function
    int single = sol.singleNumber(nums);

    // Output the result
    cout << "The element that appears only once is: " << single << endl;

    return 0;
}

