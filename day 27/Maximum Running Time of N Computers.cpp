/*
    LeetCode 2141 — Maximum Running Time of N Computers
    ---------------------------------------------------
    Author: Your Name
    Description:
        Given n computers and a list of battery capacities,
        determine the maximum time all computers can run simultaneously.
        Batteries can be swapped instantly and reused between computers.

        Approach:
        - Binary search the answer (maximum running time T)
        - Check feasibility using sum(min(battery[i], T))
        - If total >= n * T, running for T minutes is possible.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int b : batteries) sum += (long long)b;

        long long lo = 0;
        long long hi = sum / n;  // max possible time

        auto canRun = [&](long long T) -> bool {
            long long total = 0;
            for (long long b : batteries) {
                total += min(b, T);
                if (total >= T * n) return true; // early exit
            }
            return total >= T * n;
        };

        long long ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canRun(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "Enter number of computers: ";
    cin >> n;

    cout << "Enter number of batteries: ";
    cin >> m;

    vector<int> batteries(m);
    cout << "Enter battery capacities:\n";
    for (int i = 0; i < m; i++) {
        cin >> batteries[i];
    }

    Solution sol;
    long long result = sol.maxRunTime(n, batteries);

    cout << "\nMaximum running time for all computers = " << result << " minutes\n";

    return 0;
}
