/*
Question-
https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

Intuition-
We can solve this problem using recursion. The idea is to recur through the tree and for each node 
return the height of the subtree rooted at it. While recursing, if we encounter a node which is unbalanced, we return -1. 
This way we can check for each node recursively and find out if the complete tree is balanced or not.

Implementation-
We will use a recursive function solve() which will return the height of the subtree rooted at the current node.
We will call this function for each node and if we encounter a node which is unbalanced, we will return -1.
We will also check for the left and right subtrees of the current node and if any of them is unbalanced, we will return -1.
If the current node is balanced, we will return the height of the subtree rooted at it.
We will call this function for the root node and if it returns -1, we will return false else we will return true.

Complexities-
TC: O(N)
SC: O(H) where H is the height of the tree
*/

#include<bits/stdc++.h>
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int solve(Node* root) {
        
        if (root == NULL)
            return 0;
            
        int lh = solve(root->left);
        if (lh == -1)
            return -1;
        int rh = solve(root->right);
        if (rh == -1)
            return -1;
        if (abs(lh-rh) > 1)
            return -1;
            
        return 1 + max(lh, rh);
        
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int ans = solve(root);
        return ans != -1;
    }
};