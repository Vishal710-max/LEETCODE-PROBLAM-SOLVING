#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array of integers nums, remove the duplicates in-place such that each element appears only once and return the new length.
// The relative order of the elements should be kept the same.
// ✅ Approach (Two-pointer technique):
// Use two pointers: one for the current element and another for the next unique element.
// Time complexity: O(n)
// Space complexity: O(1)

// Note: The input array is assumed to be sorted.
// This solution modifies the input array in-place.
// The function returns the new length of the array after removing duplicates.


class Solution {
public: 
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0;// Pointer for the next unique element
        // Loop through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                j++;// Increment the pointer for the next unique element
                // Move the unique element to the next position
                nums[j] = nums[i];
            }
        }
        return j + 1;// Return the new length of the array, which is j + 1
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
