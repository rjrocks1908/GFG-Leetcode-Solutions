/*
A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s of length n - 1 where:

s[i] == 'I' if perm[i] < perm[i + 1], and
s[i] == 'D' if perm[i] > perm[i + 1].
Given a string s, reconstruct the lexicographically smallest permutation perm and return it.

Example 1:

Input: s = "I"
Output: [1,2]
Explanation: [1,2] is the only legal permutation that can represented by s, 
where the number 1 and 2 construct an increasing relationship.

Example 2:

Input: s = "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can be represented as "DI", 
but since we want to find the smallest lexicographical permutation, you should return [2,1,3]
*/

class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> st;
        int n = s.size();

        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (s[i] == 'D') {
                st.push(i+1);
            } else if (i != 0 and s[i] == 'I' and s[i-1] == 'D') {
                st.push(i+1);
                while (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            } else {
                ans.push_back(i+1);
            }
        }

        if (s[n-1] == 'D') {
            st.push(n+1);
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
        } else {
            ans.push_back(n+1);
        }

        return ans;

    }
};