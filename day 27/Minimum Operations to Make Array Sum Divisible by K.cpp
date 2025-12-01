/*
    Problem: Minimum Operations to Make Array Sum Divisible by K
    ------------------------------------------------------------
    Logic:
        - We compute the sum of the array.
        - The minimum number of operations needed is simply sum % k.
        - Because each operation reduces one element by 1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }

        return sum % k;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    int result = sol.minOperations(nums, k);

    cout << "\nMinimum operations required = " << result << "\n";

    return 0;
}
