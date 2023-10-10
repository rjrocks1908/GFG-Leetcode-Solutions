/*
Question-
https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

Intuition-
The idea is to first locate the target node. While locating the target node save the parents of every node
in a appropiate data structure, here i'm using a Map. Now we are going to do a BFS and the starting point will 
be the target node itself. Now explore all the surrounding node to identify nodes at specified distance 'k'.

Implementation-
1. Create a map to store parents of every node.
2. Find the first node in the preorder traversal whose value will be equal to the given target node.
3. Now while finding the target node, store all the parents of every node in the map.
4. Now perform a BFS with starting point as the target node with distance 0.
5. Traverse the tree backwards using parent map.
6. Traverse the right and left subtree.
7. Store elements in a vector when distance == k.
8. Sort the vector and return it.

Complexities-
TC: O(N*logN)
SC: O(N)
*/

#include<bits/stdc++.h>
class Solution
{
private:
public:
    //mp to store parent
    unordered_map<Node*, Node*> mp;
    void findNode(Node* root, Node* &node, int target) {
        
        if (root == NULL) {
            return;
        }
        
        if (node == NULL and root->data == target) {
            node = root;
        }
        
        if (root->left) {
            mp[root->left] = root;
            findNode(root->left, node, target);
        }
        
        if (root->right) {
            mp[root->right] = root;
            findNode(root->right, node, target);
        }
        
    }

    vector<int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        Node* node = NULL;
        findNode(root, node, target);
        
        queue<pair<Node*, int>> q;
        q.push({node, 0});
        vector<int> ans;
        unordered_set<Node*> vis;
        
        while (!q.empty()) {
            
            Node *curr = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            if (dis == k) 
                ans.push_back(curr->data);
            
            if (dis > k)
                continue;
            
            vis.insert(curr);
            
            //Checking parent
            if (mp.find(curr) != mp.end() and vis.find(mp[curr]) == vis.end()) {
                q.push({mp[curr], dis+1});
            }
            
            //Checking in left subtree
            if (curr->left != NULL and vis.find(curr->left) == vis.end()) {
                q.push({curr->left, dis+1});
            }
            
            //Checking in right subtree
            if (curr->right != NULL and vis.find(curr->right) == vis.end()) {
                q.push({curr->right, dis+1});
            }
            
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};