/*
Question-
https://practice.geeksforgeeks.org/problems/floor-in-bst/1

Intuition-
Traverse the tree by comparing the root->data with x.

Implementation-
1. Run a loop until root is not NULL.
2. check if root->data is equal to x, if yes then return x.
3. else if root->data is greater than x, then move to left subtree.
4. else if root->data is less than x, then move to right subtree. also keep updating the ans with max of ans and root->data.

Complexities-
TC: O(N)
SC: O(1)
*/

#include<bits/stdc++.h>
class Solution{
public:
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        
        while (root != NULL) {
            if (root->data == x) {
                return x;
            } else if (root->data > x) {
                root = root->left;
            } else {
                ans = max(ans, root->data);
                root = root->right;
            }
        }
        
        return ans;
    }
};