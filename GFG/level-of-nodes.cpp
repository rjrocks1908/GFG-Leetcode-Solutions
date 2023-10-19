/*
Question-
https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1

Intuition-
By using BFS, we can find the level of the node X.
Traverse the graph using BFS and keep track of the level of the node.

Implementation-
1. Create a queue and push the source node and its level.
2. Create a visited array and mark the source node as visited.
3. While the queue is not empty, pop the front element and check if it is the required node.
4. If it is the required node, return the level.
5. Else, push all the adjacent nodes of the popped node into the queue if they are not visited and mark them as visited.
6. If the required node is not found, return -1.

Complexities-
TC: O(V+E)
SC: O(V)
*/

#include<bits/stdc++.h>
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here
	    vector<bool> vis(v, false);
	    queue<pair<int,int>> q;
	    q.push({0,0});
	    vis[0] = true;
	    
	    while (!q.empty()) {
	        int node = q.front().first;
	        int lvl = q.front().second;
	        q.pop();
	        
	        if (node == x) {
	            return lvl;
	        }
	        
	        for (auto u: adj[node]) {
	            if (!vis[u]) {
	                vis[u] = true;
	                q.push({u, lvl+1});
	            }
	        }
	    }
	    
	    return -1;
	}
};