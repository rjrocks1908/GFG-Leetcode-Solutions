/*
Question-
https://leetcode.com/problems/pascals-triangle-ii/

Intuition-
We will be using DP here. Computing the previous subproblem and using it to compute the next subproblem.

Implementation-
We will be using a 2D vector to store the values of the triangle. We will be using the formula- dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
We will be using the same vector to store the previous subproblem and using it to compute the next subproblem.

Complexities-
TC: O(n^2)
SC: O(n^2)
*/

#include <bits/stdc++.h>
class Solution {
public:
    vector<int> getRow(int idx) {
        vector<vector<int>> dp(idx+1, vector<int>(idx+1,0));

        for (int i=0; i<=idx; i++) {
            for (int j=0; j<=i; j++) {
                if (j == 0 or j == i) {
                    dp[i][j] = 1;
                    continue;
                }

                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        return dp[idx];

    }
};

/*
Question-
https://leetcode.com/problems/pascals-triangle-ii/

Intuition-
We will be using DP here. Computing the previous subproblem and using it to compute the next subproblem.

Implementation-
This approach is spaced optimized approach of the previous solution. Where we will be using 2 vectors to 
store the previous and current subproblem.

Complexities-
TC: O(n^2)
SC: O(n)
*/

class Solution {
public:
    vector<int> getRow(int idx) {
        vector<vector<int>> dp(idx+1, vector<int>(idx+1,0));
        vector<int> prev(idx+1);

        for (int i=0; i<=idx; i++) {
            vector<int> curr(idx+1);
            for (int j=0; j<=i; j++) {
                if (j == 0 or j == i) {
                    curr[j] = 1;
                    continue;
                }

                curr[j] = prev[j-1] + prev[j];
            }
            prev = curr;
        }

        return prev;

    }
};