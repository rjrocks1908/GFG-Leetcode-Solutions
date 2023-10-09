/*
Question-
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Intuition-
We know that the nums array is non-decreasing so we can think of a binary search solution
to find the first index and last index of the given element.

Implementation-
By using binary search we will find the first index and last index of the target element.
We will be handling the edge cases separately why? because it is much easier to handle them
initially rather while performing the binary search. Edge cases would be when element is at 0th
and at last position in an array.

We are running two binary separately for finding first index and last index. we just modified the
binary search a little.

Complexities-
TC: O(log(N))
SC: O(1)
*/

#include<bits/stdc++.h>
class Solution {
public:
    int findex(vector<int> &arr, int tar) {

        int n = arr.size();
        int low = 0;
        int high = n-1;

        if (arr[low] == tar)
            return low;
        
        if (arr[high] == tar and n > 1 and arr[high-1] != tar)
            return high;

        while (low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == tar and arr[mid-1] != tar) {
                return mid;
            } else if (arr[mid] < tar) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return -1;

    }

    int lindex(vector<int> &arr, int tar) {

        int n = arr.size();
        int low = 0;
        int high = n-1;

        if (n>1 and arr[low] == tar and arr[low+1] != tar)
            return low;
        
        if (arr[high] == tar)
            return high;
        
        while(low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == tar and arr[mid+1] != tar) {
                return mid;
            } else if (arr[mid] > tar) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return -1;

    }

    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0) {
            return {-1,-1};
        }

        int first = findex(nums, target);
        int last = lindex(nums, target);
        return {first, last};
    }
};