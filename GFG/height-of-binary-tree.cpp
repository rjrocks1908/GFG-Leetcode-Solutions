/*
Question-
https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

Intuition-
By using preorder traversal or postorder we can find the maximum height of the tree.

Implementation-
Base case - when node == NULL return 0 why? because NULL indicates that the tree is of zero height.
Add 1 in every recursive callback and find the max out of left subtree and right subtree.

Complexities-
TC: O(N)
SC: O(N)
*/

#include<bits/stdc++.h>
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if (node == NULL)
            return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
};