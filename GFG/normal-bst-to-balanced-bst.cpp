/*
Question-
https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

Intuition-
1. Store the inorder traversal of the BST in an array.
2. Build a balanced BST from the array.

Implementation-
1. Store the inorder traversal of the BST in an array.
2. Build a balanced BST from the array. To build the balanced tree, we will use the following approach-
    1. Get the Middle of the array and make it root.
    2. Recursively do same for left half and right half.
        a) Get the middle of left half and make it left child of the root
            created in step 1.
        b) Get the middle of right half and make it right child of the
            root created in step 1.

Complexities-
TC: O(N)
SC: O(N)
*/

#include<bits/stdc++.h>
class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void inorder(Node* root, vector<int> &nodes) {
        
        if (root == NULL)
            return;
            
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
        
    }
    
    Node* solve(int left, int right, vector<int> &nodes) {
        
        if (left > right) {
            return NULL;
        }
        
        int mid = (left + right)/2;
        Node* newnode = new Node(nodes[mid]);
        newnode->left = solve(left, mid-1, nodes);
        newnode->right = solve(mid+1, right, nodes);
        return newnode;
        
    }
    
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> nodes;
    	inorder(root, nodes);
    	return solve(0, nodes.size()-1, nodes);
    }
};