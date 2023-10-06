class Solution {
public:
    /*
    Question-
    https://leetcode.com/problems/integer-break/

    Intuition-
    Try all possible combination of products and splits and get the maximum product
    out of them.

    Implementation-
    Let's say we have an integer "num" and split it into two - i and num-i.
    The highest product possible would be i*BEST where BEST is the highest possible product
    which is num-i.

    We have the following base cases for this function:

    If num == 1, then it isn't possible to split the number up, so we just return 1.
    If num == 2, then it would be better to not split the number at all, 
    since the only possible split 1 * 1 is less than 2, so just return 2. 
    The exact same argument can be made for num == 3: the only possible split 
    1 * 2 is less than 3 itself, so just return 3.

    Otherwise, we have two options:

    Don't split the number up at all. We can initialize the answer as ans = num.
    Split the number. We can try all possible splits. Iterate i from 2 until num. 
    For each value of i, try to update ans with i * dp(num - i) if it is larger.
    You may be thinking: what about the constraint where we need to have at least 2 integers? 
    We need to check for 2 separate cases before performing the recursion.

    If n == 2, we immediately return 1. The only possible split is 1 * 1.
    If n == 3, we immediately return 2. The only possible split is 1 * 2.

    We need to explicitly check for these cases before going into the recursion, otherwise, 
    we would incorrectly return a larger answer since we initialize ans = num.

    Complexities-
    TC: O(N^2)
    SC: O(N)
    */

    int solve(int n, vector<int> &dp) {

        if (n <= 3) {
            return n;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int ans = n;
        for (int i=2; i<n; i++) {
            ans = max(ans, i*solve(n-i, dp));
        }

        return dp[n] = ans;

    }

    int solvetab(int n, vector<int> &dp) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int i=4; i<=n; i++) {
            int ans = i;
            for (int j=2; j<i; j++) {
                ans = max(ans, j*dp[i-j]);
            }
            dp[i] = ans;
        }

        return dp[n];
    }

    /*
    Intuition-
    We know that if we split the numbers in 3s we can get the maximum product.
    We have found this using the differentiation and getting the maximum point at a particular tangent.
    Explanation is in the question link

    Implementation-
    Now we are breaking n into 3s if the number n is simply divisible by 3 then we can return 3^(n/3).
    
    If the number gives n%3 == 1 then we can simply add 1 to one of the 3s and get the 4 or we can also say that 4=2+2. 
    So removing one 3 and multiplying with 4 explicitly. we get 3^(n/3-1)*4.

    Likewise if the number gives n%3 == 2 then we have a extra 2 which we can multiply to the result.
    Giving result as 3^(n/3)*2.

    Complexities-
    TC: O(logN)
    SC: O(1)
    */

    int solvemath(int n) {

        if (n%3 == 0) {
            return pow(3, n/3);
        }

        if (n%3 == 1) {
            return pow(3, n/3-1)*4;
        }

        return pow(3, n/3)*2;

    }

    int integerBreak(int n) {
        if (n <= 3) {
            return n-1;
        }

        // vector<int> dp(n+1, -1);

        // return solvetab(n, dp);
        return solvemath(n);

    }
};