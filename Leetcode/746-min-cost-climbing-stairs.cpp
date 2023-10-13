/*
Question-
https://leetcode.com/problems/min-cost-climbing-stairs/

Intuition-
We will be using dynamic programming to solve this problem.
We will recursilely find all possible steps made by the person and return the minimum among them.
So simple idea is that we will be at ith step and we can either come from i-1th step or i-2th step.
So we will find the minimum among them and return it.
There can be multiple subproblems so we will be using memoization to store the results of the subproblems.

Implementation-
We will be using a vector to store the results of the subproblems.
We will be using a recursive function to find the minimum cost.

Complexities-
TC: O(n)
SC: O(n)
*/

#include <bits/stdc++.h>
class Solution {
public:
    int solve(int n, vector<int> &cost, vector<int> &dp) {

        if (n == 0 or n == 1) {
            return cost[n];
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int left = cost[n] + solve(n-1, cost, dp);
        int right = cost[n] + solve(n-2, cost, dp);

        return dp[n] = min(left, right);

    }

    int solvetab(int n, vector<int> &cost, vector<int> &dp) {

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i=2; i<=n; i++) {
            int left = cost[i]+dp[i-1];
            int right = cost[i]+dp[i-2];
            dp[i] = min(left, right);
        }

        return dp[n];

    }

    int solveSpace(int n, vector<int> &cost) {

        int prev2 = cost[0];
        int prev = cost[1];

        if (n == 0) return prev2;
        if (n == 1) return prev;

        for (int i=2; i<=n; i++) {
            int left = cost[i]+prev;
            int right = cost[i]+prev2;
            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();

        vector<int> dp(n+1, -1);
        // int ans = min(solve(n-1, cost, dp), solve(n-2, cost, dp));
        // int ans = min(solvetab(n-1, cost, dp), solvetab(n-2, cost, dp));
        int ans = min(solveSpace(n-1, cost), solveSpace(n-2, cost));

        return ans;
    }
};