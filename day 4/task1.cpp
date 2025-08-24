#include <iostream>
#include <unordered_set>  // For storing visited numbers to detect cycles
using namespace std;

// Helper function to calculate the sum of the squares of digits
int getNext(int n) {
    int sum = 0;

    // Loop through each digit
    while (n > 0) {
        int digit = n % 10;       // Extract last digit
        sum += digit * digit;     // Square it and add to sum
        n /= 10;                  // Remove last digit
    }

    return sum;  // Return the new number
}

// Main function to check if a number is a Happy Number
bool isHappy(int n) {
    unordered_set<int> seen;  // Set to store numbers we've already seen

    // Keep transforming n until it becomes 1 or loops
    while (n != 1) {
        // If we see the same number again, it's a cycle → not happy
        if (seen.count(n)) {
            return false;
        }

        seen.insert(n);       // Mark current number as seen
        n = getNext(n);       // Get the next number from sum of squares of digits
    }

    return true;  // If we reached 1, it's a happy number
}

// Main program to run
int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Check and print result
    if (isHappy(n)) {
        cout << n << " is a Happy Number!" << endl;
    } else {
        cout << n << " is NOT a Happy Number." << endl;
    }

    return 0;
}
