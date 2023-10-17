/*
Question-
https://leetcode.com/problems/validate-binary-tree-nodes/

Intuition-
To be a valid tree, it must have exactly one root, no cycles and every node must be reachable from the root.
Also every node must have a single parent except the parent.
Now we can solve this question using DFS or BFS. First we will find the root node of the tree using findRoot function.
Then we will do a DFS from the root node and check if all the nodes are reachable from the root node.

Implementation-
We would be using stack to perform DFS and queue for BFS.
In this implementation, we will be using DFS. To do BFS only change stack to queue and all other code would be the same.
1. Now to find the root node we would be using set to make lookup operation to O(1) time. 
2. Root will that number which is not present in the set or not present in the left and right arrays.
3. findRoot will return -1 if we cannot find the root node. In that case we can simply return false.
4. Now we will do DFS from the root node. We will use a stack to perform DFS. A set to keep track of visited nodes.
5. Seen set will be used to validate if there is a cycle in the graph.
6. We will push the root node in the stack and mark it as visited.
7. Now there can be a case in which graph is disconnected, in that case we will not be able to visit all the nodes.
8. So the seen set size must be less than n.
9. Thats why we are return seen.size() == n. to handle disconnected trees.

Complexities-
TC: O(N)
SC: O(N)
*/

#include <bits/stdc++.h>
class Solution {
public:
    int findRoot(int n, vector<int> &left, vector<int> &right) {
        unordered_set<int> child;
        child.insert(left.begin(), left.end());
        child.insert(right.begin(), right.end());

        for (int i=0; i<n; i++) {
            if (child.find(i) == child.end())
                return i;
        }

        return -1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        
        int root = findRoot(n, left, right);
        if (root == -1) return false;

        unordered_set<int> seen;
        stack<int> st;
        seen.insert(root);
        st.push(root);

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            int children[] = {left[node], right[node]};
            for (int child : children) {
                if (child != -1) {
                    if (seen.find(child) != seen.end()) {
                        return false;
                    }
                    
                    st.push(child);
                    seen.insert(child);
                }
            }
        }

        return seen.size() == n;

    }
};