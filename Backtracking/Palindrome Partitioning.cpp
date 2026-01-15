/*
 * Problem: Palindrome Partitioning
 * Link: https://leetcode.com/problems/palindrome-partitioning/
 * Time Complexity: O(2^N * N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans, vector<string>& temp, string s,
                int i) {
        // base case
        if (i == s.size()) {
            ans.push_back(temp);
            return;
        }
        // explore all possible partitions
        for (int start = i + 1; start <= s.size(); start++) {
            if (isPalindrome(s, i, start - 1)) {
                temp.push_back(s.substr(i, start - i));
                helper(ans, temp, s, start);
                // backtrack to explore other partitions
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        // try for all possible partitions
        // for each partition check if this substring is a palindrome or not
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans, temp, s, 0);
        return ans;
    }
};
