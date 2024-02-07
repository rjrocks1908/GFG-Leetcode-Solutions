/*
Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum distance between them. 
The given two nodes are guaranteed to be in the binary tree and all node values are unique.

Input:
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 
3
Explanation: 
We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to reach node 22. 
The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.

Hint:
Find LCA. Now from LCA find the distance of the two nodes.
*/

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root, int a, int b) {
        
        if (root == NULL) {
            return NULL;
        }
        
        if (root->data == a or root->data == b) {
            return root;
        }
        
        Node* lLca = lca(root->left, a, b);
        Node* rLca = lca(root->right, a, b);
        
        if (lLca != NULL and rLca != NULL) {
            return root;
        }
        
        if (lLca != NULL)
            return lLca;
        else
            return rLca;
    }
    
    int distance(Node *root, int tar) {
        
        if (root == NULL) {
            return -1;
        }
        
        if (root->data == tar) {
            return 0;
        }
        
        int left = distance(root->left, tar);
        int right = distance(root->right, tar);
        
        if (left >= 0) {
            return left + 1;
        } else if (right >= 0) {
            return right + 1;
        } else {
            return -1;
        }
        
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lcaNode = lca(root, a, b);
        
        return distance(lcaNode, a) + distance(lcaNode, b);
        
    }
};