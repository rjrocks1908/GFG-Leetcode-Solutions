/*
Question-
https://leetcode.com/problems/flatten-nested-list-iterator/

Intuition-
Use a stack to store the elements in reverse order.
We will use a dfs to traverse the nested list and store the elements in the stack.

Implementation-
1. Create a stack of integers.
2. Create a dfs function that takes a vector of NestedInteger as input.
3. For each element in the vector, if it is an integer, push it to the stack.
4. If it is a list, call the dfs function on the list.

Complexities-
TC: O(N)
SC: O(N)
*/

#include <bits/stdc++.h>
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<int> st;
public:
    void dfs(vector<NestedInteger> &nlist) {
        for (int i=nlist.size()-1; i>=0; i--) {
            if (nlist[i].isInteger()) {
                st.push(nlist[i].getInteger());
            } else {
                dfs(nlist[i].getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int num = st.top();
        st.pop();
        return num;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */