/*
Question-
https://leetcode.com/problems/power-of-four/

Intuition-
1. Check if n is power of 2 - To check if n is power of 2, we can use the trick that n & n-1 will be 0. Why, because we know that
n is power of 2, so it will have only one bit set. So, n-1 will have all bits set except the bit which is set in n. So, n & n-1 gives 0 always.
2. Check if the power is even - Now we know that n is power of 2. So, we need to check if the power is even. If the power is even, 
then the number is always power of 4. Why, because if the power is even, then the bit set in n will be at even position.

Implementation-
1. Check if n is power of 2.
2. If yes, then check if the power is even or not. Otherwise return false.

Complexities-
TC: O(1)
SC: O(1)
*/

#include <bits/stdc++.h>
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0 or (n & n-1) != 0)
            return false;

        int count=0;
        for (int i=1; i<=32; i++) {
            if ((n&1) == 1) {
                break;
            } else {
                n >>= 1;
                count++;
            }
        }

        return count%2 == 0;
    }
};