/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair 
(answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
*/


class Solution {
public:
    // ===========================DP solution==============================
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int lastIdx = 0;
        int maxL = INT_MIN;

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]%nums[j] == 0) {
                    if (dp[i] < dp[j]+1) {
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                    }

                    if (dp[i] > maxL) {
                        maxL = dp[i];
                        lastIdx = i;
                    }
                }
            }
        }

        vector<int> ans;
        while (lastIdx >= 0) {
            ans.push_back(nums[lastIdx]);
            lastIdx = prev[lastIdx];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    // ==========================Backtracking solution==========================
    int n;
    void solve(vector<int> &nums, int idx, int prev, vector<int> &temp, vector<int> &ans) {
        
        if (idx == n) {
            if (temp.size() > ans.size()) {
                ans = temp;
            }
            return;
        }

        if (prev == -1 or nums[idx]%prev == 0) {
            temp.push_back(nums[idx]);
            solve(nums, idx+1, nums[idx], temp, ans);
            temp.pop_back();
        }

        solve(nums, idx+1, prev, temp, ans);

    }

    vector<int> largestDivisibleSubset(vector<int> &nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<int> ans;
        solve(nums, 0, -1, temp, ans);
        return ans;
    }
};