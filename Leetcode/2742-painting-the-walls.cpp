/*
Question-
https://leetcode.com/problems/painting-the-walls/

Intuition-
Let's say that we have the paid painter paint the ithi^{th}ith wall. It costs us cost[i] money. 
The paid painter will paint 1 wall and be occupied for time[i] time. While the paid painter is occupied, 
the free painter can paint time[i] walls (since the free painter paints one wall per unit of time). 
Overall, we spent cost[i] money to paint 1 + time[i] walls.

Implementation-
Let dp(i, remain) be a function that returns the minimum cost to paint remain walls when considering index i and beyond. 
We have two base cases here.

If remain <= 0, we have painted all the walls. We can return 0.
If i == n, we have run out of walls to put the paid painter on and the task is impossible. We return a large value like infinity.
Now, how do we calculate a given state (i, remain)? For the ithi^{th}i 
th
  wall, we have two options. We can either hire the paid painter for this wall or not hire them.

If we hire them, as mentioned above, we spend cost[i] and paint 1 + time[i] walls. Then, we move to the next index. 
Thus, the cost of this option is cost[i] + dp(i + 1, remain - 1 - time[i]).
If we don't hire them, we simply move to the next index. The cost of this option is dp(i + 1, remain).
Let's call the first option paint and the second option dontPaint. Then, dp(i, remain) = min(paint, dontPaint).

Complexities-
TC: O(n^2)
SC: O(n^2)
*/

#include<bits/stdc++.h>
class Solution {
public:
    int solve(int i, int remain, vector<int> &cost, vector<int> &time, vector<vector<int>> &dp) {

        if (remain <= 0) {
            return 0;
        }

        if (i == cost.size()) {
            return 1e9;
        }

        if (dp[i][remain] != -1) {
            return dp[i][remain];
        }

        int take = cost[i] + solve(i+1, remain - 1 - time[i], cost, time, dp);
        int nottake = solve(i+1, remain, cost, time, dp);

        return dp[i][remain] = min(take, nottake);

    }

    int paintWalls(vector<int> &cost, vector<int> &time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = solve(0, n, cost, time, dp);
        return ans;
    }
};