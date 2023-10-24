/*
Question-
https://leetcode.com/problems/find-largest-value-in-each-tree-row/

Intuition-
We will use BFS to traverse the tree level by level. 
We will keep track of the maximum value in each level and push it into the answer vector.

Implementation-
1. if the root is empty, return empty vector
2. Initialize a ans vector, and a queue with the root to perform BFS
3. while the queue is not empty, we will find the size of the queue and iterate over it
4. for each node, we will find the maximum value in the level and push it into the ans vector
5. Return ans vector

Complexities-
TC: O(N)
SC: O(N)
*/


#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN;
            for (int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr->val);
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};