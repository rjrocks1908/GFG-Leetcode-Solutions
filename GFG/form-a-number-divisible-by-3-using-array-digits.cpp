/*
Question-
https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1

Intuition-
A number is divisible by 3 if the sum of its digits is divisible by 3.

Implementation-
Find the sum of all the digits of the array and check if it is divisible by 3.

Complexities-
TC: O(N)
SC: O(1)
*/

class Solution {
  public:
    int isPossible(int n, int arr[]) {
        // code here
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += arr[i]%3;
        }
        
        return sum%3 == 0;
    
    }
};