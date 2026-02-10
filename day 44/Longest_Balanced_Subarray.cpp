#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
3719. Longest Balanced Subarray I
--------------------------------
You are given an integer array nums.

A subarray is called balanced if:
- The number of DISTINCT even numbers
  equals
- The number of DISTINCT odd numbers.

Return the length of the longest balanced subarray.
*/

/*
# Intuition
- We only care about DISTINCT even and odd values, not frequency.
- For a fixed starting index, we can expand the subarray to the right.
- While expanding, we track:
  - A set of distinct even numbers
  - A set of distinct odd numbers
- Whenever both sets have equal size, the subarray is balanced.

Since nums.length ≤ 1500, an O(n²) solution is acceptable.
*/

/*
# Approach
1. Initialize answer = 0.
2. For each starting index i:
   - Create two empty sets: evenSet and oddSet.
3. For each ending index j from i to n-1:
   - If nums[j] is even → insert into evenSet.
   - Else → insert into oddSet.
4. If evenSet.size() == oddSet.size():
   - Update answer with max(answer, j - i + 1).
5. Return answer.
*/

/*
# Complexity
- Time: O(n²)
- Space: O(n) for the sets
*/

class Solution {
public:
    int longestBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet, oddSet;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if (evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// Driver code for local testing
int main() {
    Solution sol;

    vector<int> nums1 = {2, 5, 4, 3};
    cout << sol.longestBalancedSubarray(nums1) << endl; // 4

    vector<int> nums2 = {3, 2, 2, 5, 4};
    cout << sol.longestBalancedSubarray(nums2) << endl; // 5

    vector<int> nums3 = {1, 2, 3, 2};
    cout << sol.longestBalancedSubarray(nums3) << endl; // 3

    return 0;
}
