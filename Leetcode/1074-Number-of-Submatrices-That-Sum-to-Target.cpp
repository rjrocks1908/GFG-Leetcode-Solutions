class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i=0; i<n; i++) {
            for (int j=1; j<m; j++) {
                mat[i][j] += mat[i][j-1];
            }
        }

        int res = 0;
        for (int startcol = 0; startcol < m; startcol++) {
            for (int j = startcol; j<m; j++) {
                unordered_map<int,int> mp;
                mp[0] = 1;
                int cursum = 0;
                for (int row=0; row<n; row++) {
                    cursum += mat[row][j] - (startcol > 0 ? mat[row][startcol-1] : 0);
                    if (mp.find(cursum-tar) != mp.end()) {
                        res += mp[cursum-tar];
                    }
                    mp[cursum]++;
                }
            }
        }

        return res;
    }
};