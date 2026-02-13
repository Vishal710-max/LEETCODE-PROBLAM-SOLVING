#include <iostream>
#include <vector>
using namespace std;

/*
27. Remove Element
------------------
Given an integer array nums and an integer val,
remove all occurrences of val in-place.

Return the number of elements in nums which are not equal to val (k).

The first k elements of nums must contain the valid elements.
The remaining elements are not important.
*/

/*
# Intuition
- We need to remove elements in-place.
- Use two-pointer technique:
    - One pointer (i) scans the array.
    - One pointer (k) tracks position to place valid elements.
- Every time we find an element not equal to val,
  we place it at index k and increment k.
*/

/*
# Approach
1. Initialize k = 0.
2. Traverse the array from i = 0 to n-1:
   - If nums[i] != val:
       - Assign nums[k] = nums[i]
       - Increment k
3. Return k.
*/

/*
# Complexity
- Time: O(n)
- Space: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;  // pointer for placing valid elements
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {3,2,2,3};
    int k1 = sol.removeElement(nums1, 3);
    cout << k1 << endl;  // Expected: 2

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int k2 = sol.removeElement(nums2, 2);
    cout << k2 << endl;  // Expected: 5

    return 0;
}
