/*
Platform: LeetCode
Problem Name: 2273. Find Resultant Array After Removing Anagrams
Problem Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
Problem Code: 2273

Description:
You are given a 0-indexed string array `words`, where each word consists of lowercase English letters.

You need to remove all strings that are anagrams of the previous string in the array.  
Return the array after removing the anagrams.  
It can be shown that the answer will be unique.

Example 1:
Input: words = ["abba","baba","bbaa","cd","cd"]
Output: ["abba","cd"]
Explanation:
- "abba" and "baba" are anagrams, so we remove "baba".
- "abba" and "bbaa" are anagrams, so we remove "bbaa".
- "bbaa" and "cd" are not anagrams, so we keep "cd".
- "cd" and "cd" are anagrams, so we remove the second "cd".

Example 2:
Input: words = ["a","b","c","d","e"]
Output: ["a","b","c","d","e"]

Approach:
1. Iterate through each word in the input list.
2. For each word, compare it with the last word in the result array.
3. If the current word is not an anagram of the previous word, add it to the result.
4. Otherwise, skip it.
5. To check if two words are anagrams:
   - Sort both strings alphabetically and compare them.

Time Complexity: O(n * k log k)
   - n = number of words, k = maximum word length (for sorting each word)
Space Complexity: O(n * k)
   - For storing sorted strings and the result vector.

Key Insight:
By comparing each word only with its immediate previous valid word, 
we ensure minimal comparisons and remove only consecutive anagrams.

Example:
Input: words = ["ab","ba","cd","dc","cd"]
Output: ["ab","cd"]

Additional Notes:
- Sorting each word ensures accurate anagram detection.
- Alternatively, using character frequency arrays can improve performance slightly.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        for (string w : words) {
            if (result.empty() || !isAnagram(result.back(), w))
                result.push_back(w);
        }
        return result;
    }

    bool isAnagram(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        string sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        return sa == sb;
    }
};

// ------------------- Test Driver Code -------------------
int main() {
    Solution sol;

    vector<string> words1 = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> result1 = sol.removeAnagrams(words1);

    cout << "Input: [\"abba\", \"baba\", \"bbaa\", \"cd\", \"cd\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result1.size(); ++i) {
        cout << "\"" << result1[i] << "\"";
        if (i != result1.size() - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    vector<string> words2 = {"a", "b", "c", "d", "e"};
    vector<string> result2 = sol.removeAnagrams(words2);

    cout << "Input: [\"a\", \"b\", \"c\", \"d\", \"e\"]" << endl;
    cout << "Output: [";
    for (int i = 0; i < result2.size(); ++i) {
        cout << "\"" << result2[i] << "\"";
        if (i != result2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
