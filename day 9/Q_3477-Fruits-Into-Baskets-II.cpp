/*
Platform: LeetCode
Problem Name: Number of Unplaced Fruits
Problem Link: https://leetcode.com/problems/number-of-unplaced-fruits/ (example placeholder link)
Problem Code: N/A

Description:
You are given two integer arrays `fruits` and `baskets`, each of size `n`. 
- `fruits[i]` represents the size of the i-th fruit.
- `baskets[j]` represents the capacity of the j-th basket.
- Each basket can hold at most one fruit, and a fruit can be placed in a basket only if the basket’s capacity 
  is greater than or equal to the fruit’s size.
Your task is to determine how many fruits cannot be placed in any basket.

Approach:
1. Sort both `fruits` and `baskets` arrays.
2. Use two pointers:
   - One pointer `i` for fruits and another pointer `j` for baskets.
   - If `baskets[j] >= fruits[i]`, then place the fruit in that basket and move both pointers.
   - Otherwise, move only the basket pointer `j`.
3. Count how many fruits are successfully placed.
4. The answer = `total fruits - placed fruits`.

Time Complexity: O(n log n)  
- Sorting both arrays dominates the complexity.

Space Complexity: O(1)  
- Ignoring sorting space.

Key Insight:
Sorting aligns the problem with a natural greedy matching strategy:
each fruit is placed into the smallest sufficient basket, minimizing waste and maximizing placements.

Example:
Input:
    fruits  = [2, 3, 5]
    baskets = [3, 4, 2]
Output:
    1
Explanation:
- After sorting: fruits = [2, 3, 5], baskets = [2, 3, 4]
- Fruit 2 → Basket 2
- Fruit 3 → Basket 3
- Fruit 5 → No basket available
Answer = 1

Additional Notes:
This approach is more efficient than the brute-force O(n^2) method. 
It ensures each fruit is paired optimally with the smallest possible basket that fits.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        sort(fruits.begin(), fruits.end());
        sort(baskets.begin(), baskets.end());

        int i = 0, j = 0, placed = 0, n = fruits.size();
        while (i < n && j < n) {
            if (baskets[j] >= fruits[i]) {
                placed++;  // fruit placed in this basket
                i++; j++;
            } else {
                j++; // basket too small, skip
            }
        }
        return n - placed;  // unplaced fruits
    }
};

int main() {
    cout<<"Here is the Main Function";
    Solution sol;

    // Test Case 1
    vector<int> fruits1 = {2, 3, 5};
    vector<int> baskets1 = {3, 4, 2};
    cout << "Unplaced Fruits (Test Case 1): "
         << sol.numOfUnplacedFruits(fruits1, baskets1) << endl;
    // Expected: 1

    // Test Case 2
    vector<int> fruits2 = {1, 2, 3};
    vector<int> baskets2 = {3, 3, 3};
    cout << "Unplaced Fruits (Test Case 2): "
         << sol.numOfUnplacedFruits(fruits2, baskets2) << endl;
    // Expected: 0 (all fruits fit)

    // Test Case 3
    vector<int> fruits3 = {5, 6, 7};
    vector<int> baskets3 = {1, 2, 3};
    cout << "Unplaced Fruits (Test Case 3): "
         << sol.numOfUnplacedFruits(fruits3, baskets3) << endl;
    // Expected: 3 (none fit)

    return 0;
}

