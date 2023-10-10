/*
Question-
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

Intuition-
We would be using binary search to find the minimum number of operation to make the array continous.
We know that for an array to be continous, contigious elements should have a max difference of 1.
We can define the array by its bounds left and right, where left would represent the smallest number and right
would represent the largest.
so for an eg [6,3,5,4]
From above we can easily come to this conclusion that right-left = n-1. and right = left + n-1.
So for the above array if left = 3, then definitely right = 3+4-1 = 6. We can easily verify from the array itself.

Implementation-
1. Now to solve the problem we can assume every index of the array as left and find the right bound of that left bound.
2. In this way we can compute for every index and take the minimum from all.
3. To do this we need to make sure that the array should not have any duplicates, for that we can use set and other is
array should be sorted so that we can find the right bound easily using binary search in LogN time.

Sliding Window
Alternatively we can use sliding window to figure out the right bound, if we dont want to use the binary search. We know that
as left bound increase the right will remain same or increases. So to find the right we will iterate the right till we found a 
number which is just greater than the right bound.

Current Solution uses the binary search method. To implement sliding just slide the window till we find a greater element.
"while (arr[j] < arr[i] + n)"

Complexities-
TC: O(NlogN)
SC: O(N)
*/

#include<bits/stdc++.h>
class Solution {
public:
    int minOperations(vector<int> &nums) {
        set<int> s(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> arr;
        for (auto val: s) {
            arr.push_back(val);
        }

        int newn = arr.size();
        int ans = n;

        for (int i=0; i<newn; i++) {
            int left = arr[i];
            int right = left + n-1;
            int j = upper_bound(arr.begin(), arr.end(), right) - arr.begin();
            ans = min(ans,n-(j-i));
        }

        return ans;
    }
};