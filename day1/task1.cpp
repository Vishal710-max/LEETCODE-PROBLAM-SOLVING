#include <iostream>
#include <vector>
using namespace std;

// Given an array of integers nums and an integer target, return the indices of the 
//two numbers such that they add up to target.

// ✅ Approach (Brute-force):
// Use two nested loops.

// Check every pair (i, j) where j > i.

// If nums[i] + nums[j] == target, return {i, j}.

// Time complexity: O(n²)

// Space complexity: O(1)




class Solution {
public:
    // Function to find two indices such that nums[i] + nums[j] == target
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        // Loop through each element
        for (i = 0; i < nums.size(); i++) {
            // Compare with every other element ahead of it
            for (j = i + 1; j < nums.size(); j++) {
                // Check if sum equals target
                if (nums[j] == target - nums[i]) {
                    return {i, j}; // Return indices if condition matches
                }
            }
        }
        return {}; // Return empty if no such pair found
    }
};

int main() {
    Solution sol;

    // Sample input array and target
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the function
    vector<int> result = sol.twoSum(nums, target);

    // Output the result
    if (!result.empty()) {
        cout << "Indices found: " << result[0] << " and " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
