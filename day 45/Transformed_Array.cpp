#include <iostream>
#include <vector>
using namespace std;

/*
3379. Transformed Array
-----------------------
You are given an integer array nums that represents a circular array.

For each index i:
- If nums[i] > 0 → move nums[i] steps to the right.
- If nums[i] < 0 → move abs(nums[i]) steps to the left.
- If nums[i] == 0 → result[i] = 0.

Since the array is circular:
- Moving past the last element wraps around.
- Moving before the first element wraps to the end.

Return the transformed array.
*/

/*
# Intuition
- The array is circular, so we must handle wrap-around.
- Moving left or right can be simplified using modulo.
- However, C++ modulo with negative numbers can give negative results.
- To fix that, we normalize the index using:

    newIndex = ((i + nums[i]) % n + n) % n

This guarantees newIndex is always between 0 and n-1.
*/

/*
# Approach
1. Create a result vector of size n.
2. For each index i:
   - If nums[i] == 0 → result[i] = 0.
   - Else:
       - Compute newIndex using circular formula.
       - Assign result[i] = nums[newIndex].
3. Return result.
*/

/*
# Complexity
- Time: O(n)
- Space: O(n)
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int newIndex = ((i + nums[i]) % n + n) % n;
                result[i] = nums[newIndex];
            }
        }

        return result;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {3, -2, 1, 1};
    vector<int> res1 = sol.constructTransformedArray(nums1);
    for (int x : res1) cout << x << " ";
    cout << endl; // 1 1 1 3

    vector<int> nums2 = {-1, 4, -1};
    vector<int> res2 = sol.constructTransformedArray(nums2);
    for (int x : res2) cout << x << " ";
    cout << endl; // -1 -1 4

    return 0;
}
