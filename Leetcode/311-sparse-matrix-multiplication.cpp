/*
Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. 
You may assume that multiplication is always possible.

Example 1:

Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]
Example 2:

Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]
*/

class Solution {
public:
    vector<vector<pair<int,int>>> cmatrix(vector<vector<int>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<pair<int,int>>> ans(n);

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] != 0) {
                    ans[i].push_back({mat[i][j], j});
                }
            }
        }

        return ans;

    }

    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat2[0].size();

        vector<vector<pair<int,int>>> m1 = cmatrix(mat1);
        vector<vector<pair<int,int>>> m2 = cmatrix(mat2);

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int row=0; row<n; row++) {
            for (auto [val1, col1] : m1[row]) {
                for (auto [val2, col2] : m2[col1]) {
                    ans[row][col2] += val1*val2;
                }
            }
        }

        return ans;

    }
};