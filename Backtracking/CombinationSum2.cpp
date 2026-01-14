/*
 * Problem: Combination Sum 2
 * Link: https://leetcode.com/problems/combination-sum-ii/
 * Time Complexity: O(2^T * k)
 * Space Complexity: O(k*x) k - avg length of combination and x - no of combinations
 */

/* In the loop, if i > idx and candidates[i] == candidates[i-1], SKIP.
 *  This distinguishes between:
 * - Using a duplicate number in a NEW slot (Allowed: e.g., index 0 is '1', index 1 is '1')
 * - Using a duplicate number in the SAME slot (Forbidden: e.g., already tried '1' for slot 1, 
 * don't try a different '1' for slot 1)
*/


class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res,
                vector<int>& temp, int idx) {

        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates, target, res, temp, 0);
        return res;
    }
};
