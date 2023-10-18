/*
Question-
https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

Intuition-
The nodes which are inside a cycle are not safe nodes. So, we need to find the nodes which are not inside a cycle.

Implementation-
1. We will use DFS to find the nodes which are inside a cycle.
2. We will use a recursion stack to keep track of the previously visited nodes.
3. If we encouter a node which is already visited and is present in the recursion stack, then it means that we have found a cycle.
4. Automatically the nodes which are inside the cycle will be marked as true inside the recusion stack.
5. At the end we just need to fetch the nodes which are not inside the recursion stack.

Complexities-
TC: O(V+E)
SC: O(V)
*/

#include<bits/stdc++.h>
class Solution {
  public:
    bool dfs(int s, vector<int> adj[], vector<bool> &vis, vector<bool> &recst) {
        
        vis[s] = true;
        recst[s] = true;
        
        for (auto x: adj[s]) {
            if (!vis[x] and dfs(x, adj, vis, recst))
                return true;
            else if (recst[x] == true) {
                return true;
            }
        }
        
        recst[s] = false;
        return false;
        
    }
  
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<bool> vis(v, false);
        vector<bool> recst(v, false);
        
        for (int i=0; i<v; i++) {
            if (!vis[i]) {
                 dfs(i, adj, vis, recst);
            }
        }
        
        vector<int> ans;
        for (int i=0; i<v; i++) {
            if (recst[i] == false)
                ans.push_back(i);
        }
        
        return ans;
    }
};