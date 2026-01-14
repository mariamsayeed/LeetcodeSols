/*
 * Problem: Combination Sum
 * Link: https://leetcode.com/problems/combination-sum/
 * Time Complexity: O(2^T * k)
 * Space Complexity: O(T)
 */


class Solution {
public:
    void helper(vector<int>& candidates, int target, vector<vector<int>>& res,
                vector<int>& temp, int idx) {
        // base case
        if (idx == candidates.size()) {
            if (target == 0) {
                res.push_back(temp);
            }

            return;
        }
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            // pick
            helper(candidates, target - candidates[idx], res, temp, idx);
            // remove the pick element as it is pass by reference, changes is applied
            // to all the values, if not removed we will get the previous temp
            // filled with pick elements
            temp.pop_back();
        }

        // not pick
        helper(candidates, target, res, temp, idx + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 1. pick and not pick strategy
        // 2. check if the target element is greater or equal to the current element, then
        // only pick that element

        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates, target, res, temp, 0);
        return res;
    }
};
