/*
Question-
https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1

Intuition-
We can use DFS to find the transitive closure of a graph. 
We will start DFS from every node and mark all the nodes reachable from it as 1 in the resultant matrix.

Implementation-
1. We will use a 2D vector to store the resultant matrix.
2. We will use a vector to store the visited nodes.
3. We will use a variable to store the source node.
4. We will use a DFS function to mark all the nodes reachable from the source node as 1 in the resultant matrix.

Complexities-
TC: O(N^3)
SC: O(N^2)
*/

#include<bits/stdc++.h>
class Solution{
public:
    vector<vector<int>> ans;
    int source;
    void dfs(int s, vector<vector<int>> &graph, vector<bool> &vis) {
        
        vis[s] = true;
        ans[source][s] = 1;
        
        int n = graph.size();
        for (int i=0; i<n; i++) {
            if (graph[s][i] == 1 and !vis[i]) {
                dfs(i, graph, vis);
            }
        }
        
    }
    
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        ans = graph;
        vector<bool> vis;
        
        for (int i=0; i<n; i++) {
            vis = vector<bool>(n, false);
            source = i;
            dfs(i, graph, vis);
        }
        
        return ans;
        
    }
};