/*
Question-
https://leetcode.com/problems/backspace-string-compare/

Intuition-
Use stack to store the characters of the string. If the character is #, pop the top element from the stack. 
Else, push the character into the stack.

Implementation-
1. Implement 2 Stacks for each string
2. Iterate over the string and push the characters into the stack
3. If the character is #, pop the top element from the stack
4. Else, push the character into the stack
5. Compare the size of the stacks. If they are not equal, return false
6. Else, compare the top elements of the stack. If they are not equal, return false
7. Else return true.

Complexities-
TC: O(M+N)
SC: O(M+N)
*/

#include <bits/stdc++.h>
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> tt;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '#') {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(s[i]);
            }
        }

        for (int i=0; i<t.size(); i++) {
            if (t[i] == '#') {
                if (!tt.empty())
                    tt.pop();
            } else {
                tt.push(t[i]);
            }
        }

        if (st.size() != tt.size()) return false;
        if (st.empty() and tt.empty()) return true;

        while (!st.empty()) {
            if (st.top() != tt.top())
                return false;
            st.pop();
            tt.pop();
        }

        return true;
    }
};