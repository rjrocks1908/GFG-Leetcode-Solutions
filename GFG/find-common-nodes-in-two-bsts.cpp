/*
Question-
https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

Intuition-
Perform the inorder traversal on both the trees and then find the common elements in both the arrays.

Implementation-
1. Perform inorder traversal on both the trees and store the elements in a map.
2. If the element is already present in the map, then push it into the vector.
3. Return the vector.

Complexities-
TC: O(N)
SC: O(N)
*/

#include <bits/stdc++.h>
class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void inorder(Node *root, unordered_map<int,int> &mp, vector<int> &ans) {
        
        if (root == NULL)
            return;
            
        inorder(root->left, mp, ans);
        mp[root->data]++;
        if (mp[root->data] > 1) {
            ans.push_back(root->data);
        }
        inorder(root->right, mp, ans);
        
    }
    
    vector<int> findCommon(Node *root1, Node *root2)
    {
        //Your code here
        vector<int> ans;
        unordered_map<int,int> mp;
        inorder(root1, mp, ans);
        inorder(root2, mp, ans);
        return ans;
    }
};