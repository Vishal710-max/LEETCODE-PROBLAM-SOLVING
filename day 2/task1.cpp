/*
Question:
Implement a recursive linear search function that searches for a given item in an integer array
starting from the last element and moving towards the first. If the item is found, return its index;
otherwise, return -1.

Time Complexity: O(N)
Space Complexity: O(1)
Auxiliary Space Complexity: O(N) due to function call stack

Test Cases:
----------------------------------------
Input:
arr = {10, 5, 15, 21, -3, 7}
item = 21
Output:
Item found at index: 3

Input:
arr = {10, 5, 15, 21, -3, 7}
item = 50
Output:
Item not found

Input:
arr = {3, 3, 3, 3}
item = 3
Output:
Item found at index: 3  // last occurrence from the right
----------------------------------------
*/

#include <iostream>
using namespace std;

// Recursive Linear Search Function
int LinearSearch(int arr[], int index, int item)
{
    // Base case 1: if current element matches the item
    if (arr[index] == item)
        return index;

    // Base case 2: if index becomes -1, item is not found
    else if (index == -1)
        return -1;

    // Recursive call: check the previous index
    return LinearSearch(arr, index - 1, item);
}

int main() 
{
    int arr[] = {10, 5, 15, 21, -3, 7};

    // Calculate length of array
    int len = sizeof(arr) / sizeof(arr[0]);

    // Item to be searched
    int item = 21;

    /*
       Start recursion from the last index of the array (len - 1).
       This means we will search from right to left.
       Example: for len = 6, last index = 5.
    */
    int index = LinearSearch(arr, len - 1, item);

    // Display result based on the return value
    if (index >= 0)
        cout << "Item found at index: " << index;
    else
        cout << "Item not found";

    return 0;
}
