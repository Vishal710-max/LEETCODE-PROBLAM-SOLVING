/*
Platform: LeetCode
Problem Name: Simple Bank System
Problem Link: https://leetcode.com/problems/simple-bank-system/
Problem Code: (Not Applicable)

Description:
Design a simple banking system that supports the following operations:

1. **Deposit**: Deposit a given amount of money into an account.
2. **Withdraw**: Withdraw a given amount of money from an account, if sufficient balance is available.
3. **Transfer**: Transfer money between two valid accounts, if the source account has enough balance.

The class should have the following methods:

- **Bank(vector<long long>& balance)**  
  Constructor that initializes the bank system with the given account balances.

- **bool transfer(int account1, int account2, long long money)**  
  Transfers `money` from `account1` to `account2`.  
  Returns `false` if either account is invalid or if there are insufficient funds.

- **bool deposit(int account, long long money)**  
  Deposits `money` into the specified account.  
  Returns `false` if the account number is invalid.

- **bool withdraw(int account, long long money)**  
  Withdraws `money` from the specified account.  
  Returns `false` if the account number is invalid or if there are insufficient funds.

Constraints:
- 1 ≤ account ≤ n ≤ 10⁵
- 0 ≤ balance[i], money ≤ 10¹²

Approach:
- Maintain a vector `balance` where `balance[i]` stores the current balance of the (i+1)th account.
- For each operation, validate the account number and balance before performing any transaction.
- Time complexity for all operations is O(1).

Time Complexity: O(1)
Space Complexity: O(n)

Key Insight:
Using a vector to store balances allows constant-time access and updates for each account, 
making it ideal for a system with frequent transactions.

Example:
Input:
Bank bank({10, 100, 20, 50, 30});
bank.withdraw(3, 10);   // returns true, balance[3] = 10
bank.transfer(5, 1, 20); // returns true, balance[5] = 10, balance[1] = 30
bank.deposit(5, 20);    // returns true, balance[5] = 30

Output: true, true, true
*/

#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    vector<long long> balance; // Store account balances

    // Helper function to validate account number
    bool isValidAccount(int account) {
        return account >= 1 && account <= (int)balance.size();
    }

public:
    // Constructor to initialize bank with account balances
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }

    // Transfer money between two valid accounts
    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1) || !isValidAccount(account2))
            return false;
        if (balance[account1 - 1] < money)
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    // Deposit money into a valid account
    bool deposit(int account, long long money) {
        if (!isValidAccount(account))
            return false;

        balance[account - 1] += money;
        return true;
    }

    // Withdraw money from a valid account
    bool withdraw(int account, long long money) {
        if (!isValidAccount(account))
            return false;
        if (balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }

    // Debug function to print all balances
    void printBalances() {
        cout << "Current Balances: ";
        for (auto b : balance) cout << b << " ";
        cout << endl;
    }
};

// ---------------- Driver Code / Test Cases ----------------
int main() {
    vector<long long> initialBalances = {10, 100, 20, 50, 30};
    Bank bank(initialBalances);

    cout << boolalpha; // print true/false instead of 1/0
    cout << "Withdraw from account 3 (10): " << bank.withdraw(3, 10) << endl;
    bank.printBalances();

    cout << "Transfer from account 5 → 1 (20): " << bank.transfer(5, 1, 20) << endl;
    bank.printBalances();

    cout << "Deposit to account 5 (20): " << bank.deposit(5, 20) << endl;
    bank.printBalances();

    cout << "Withdraw from invalid account (7): " << bank.withdraw(7, 10) << endl;
    cout << "Transfer with insufficient funds (1 → 2, 1000): " << bank.transfer(1, 2, 1000) << endl;

    return 0;
}
