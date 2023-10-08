/*
Question-
https://leetcode.com/problems/max-dot-product-of-two-subsequences/

Intuition-
In this we need to make decisions on which number multiply with each other. And also if we use a
pair, we cannot use that pair again in the future again.

For this questions we can come across three situations.
1. We can multiply the numbers at nums1[i] and nums2[j] and then traverse both array by i+1 and j+1.
which will give us the product of nums1[i]*nums2[j] and thus this option gives the dot product of
nums1[i]*nums2[j] + solve(i+1,j+1);
2. We can move forward in nums1. This gives us the dot product of solve(i+1, j).
3. We can move forward in nums2. This gives us the dot product of solve(i, j+1).
And the answer would be the maximum from all those cases.

Now in question it is given that dot product should be non-negative but if we cannot make such case
the value should be minimum as possible. This case can only happen when one array will have all negative
and other will have all positive. So get the minimum possible product we will choose maximum negative value
and minmum positive value.

Complexities-
TC: O(N^2)
SC: O(N^2)
*/

#include<bits/stdc++.h>
class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j, vector<vector<int>> &dp) {

        if (i == nums1.size() or j == nums2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = solve(nums1, nums2, i+1, j, dp);
        int middle = nums1[i]*nums2[j] + solve(nums1, nums2, i+1,j+1, dp);
        int right = solve(nums1, nums2, i, j+1, dp);

        int ans = max({left, middle, right});

        return dp[i][j] = ans;

    }

    int solvetab(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {

        int n = nums1.size();
        int m = nums2.size();

        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                int left = dp[i+1][j];
                int middle = nums1[i]*nums2[j] + dp[i+1][j+1];
                int right = dp[i][j+1];
                dp[i][j] = max({left, middle, right});
            }
        }

        return dp[0][0];

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // int ans = solve(nums1, nums2, 0, 0, dp);
        int ans = solvetab(nums1, nums2, dp);

        return ans;
    }
};