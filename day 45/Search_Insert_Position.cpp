#include <iostream>
#include <vector>
using namespace std;

/*
35. Search Insert Position
--------------------------
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If not found, return the index where it would be inserted
in order to maintain sorted order.

You must write an algorithm with O(log n) runtime complexity.
*/

/*
# Intuition
- Since the array is sorted, we can use Binary Search.
- If target exists → return its index.
- If it does not exist → return the position where it should be inserted.
- After binary search ends:
    left will point to the correct insertion index.
*/

/*
# Approach
1. Initialize:
   - left = 0
   - right = n - 1
2. While left <= right:
   - Find mid
   - If nums[mid] == target → return mid
   - If nums[mid] < target → search right half
   - Else → search left half
3. When loop ends:
   - left will be the correct insertion position.
4. Return left.
*/

/*
# Complexity
- Time: O(log n)
- Space: O(1)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // left is the correct insertion position
        return left;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {1,3,5,6};
    cout << sol.searchInsert(nums1, 5) << endl; // 2

    vector<int> nums2 = {1,3,5,6};
    cout << sol.searchInsert(nums2, 2) << endl; // 1

    vector<int> nums3 = {1,3,5,6};
    cout << sol.searchInsert(nums3, 7) << endl; // 4

    vector<int> nums4 = {1,3,5,6};
    cout << sol.searchInsert(nums4, 0) << endl; // 0

    return 0;
}
