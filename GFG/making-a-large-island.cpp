/*
Question-
https://practice.geeksforgeeks.org/problems/making-a-large-island/1

Intuition-
Explore every island using DFS, count it area, give it an island index and save the result to a {index:area} map.
Loop every cell == 0, check its connected islands and calculate total islands area.

Implementation-
1. Explore every island using DFS, count it area, give it an island index and save the result to a {index:area} map.
2. Loop every cell == 0, check its adajacent islands that is up, left, bottom, and right.
3. To prevent duplicate island, use a set to save the index of islands.
4. Calculate total islands area and update maxArea.

Complexities-
TC: O(N^2)
SC: O(N^2)
*/

#include<bits/stdc++.h>
class Solution
{
public:
    unordered_map<int, int> mp;
    int ind;
    bool isvalid(int x, int y, int n) {
        return x>=0 and x<n and y>=0 and y<n;
    }
    
    void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &vis, int &area) {
        int n = grid.size();
        if (x<0 or x>=n or y<0 or y>=n or grid[x][y] == 0 or vis[x][y])
            return;
            
        vis[x][y] = true;
        area++;
        grid[x][y] = ind;
            
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            dfs(nx, ny, grid, vis, area);
        }
        
    }
    
    int largestIsland(vector<vector<int>> &grid) 
    {
        // Your code goes here.
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int maxarea = INT_MIN;
        
        ind = 2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1 and !vis[i][j]) {
                    int area = 0;
                    dfs(i, j, grid, vis, area);
                    mp[ind] = area;
                    maxarea = max(maxarea, area);
                    ind++;
                }
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    int dx[] = {-1,1,0,0};
                    int dy[] = {0,0,-1,1};
                    int totalarea = 0;
                    for (int k=0; k<4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if (isvalid(nx,ny,n)) {
                            int index = grid[nx][ny];
                            if (st.find(index) == st.end()) {
                                int area = mp[index];
                                totalarea += area;
                                st.insert(index);
                            }
                        }
                    }
                    maxarea = max(maxarea, totalarea+1);
                }
            }
        }
        
        return maxarea;
        
    }
};