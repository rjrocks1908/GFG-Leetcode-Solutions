/*
Question-
https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

Intuition-
We will use postorder traversal to solve this problem. We will store the string representation of the subtree in a set. 
If we find a duplicate subtree, we will return true. This method is called the serialization of the tree.

Implementation-
1. We will use postorder traversal to solve this problem.
2. Here if we get a string as "#" that means we got a duplicate subtree. And here null is represented as "$".
3. We will represent the subtree as a string. For example, if we have a tree like this-
    1
   / \
  2   3
     / \
    4   5
  Then the string representation of the subtree rooted at 3 will be "34$$5$$". And for the leaves node 2, 4, 5, 
  the string representation will be "2$$", "4$$", "5$$" respectively.
4. We will store the string representation of the subtree in a set. If we find a duplicate subtree, we will return "#".

Complexities-
TC: O(N)
SC: O(N)
*/

#include<bits/stdc++.h>
class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_set<string> st;
    string solve(Node* root) {
        
        if (root == NULL) {
            return "$";
        }
        
        string lstr = solve(root->left);
        if (lstr == "#") return lstr;
        
        string rstr = solve(root->right);
        if (rstr == "#") return rstr;
        
        string s;
        s += (root->data + lstr + rstr);
        
        if (s.size() > 3 and st.find(s) != st.end())
            return "#";
        
        st.insert(s);
        
        return s;
        
    }
    
    int dupSub(Node *root) {
        // code here
        string s = solve(root);
        if (s == "#") {
            return 1;
        }
        return 0;
    }
};