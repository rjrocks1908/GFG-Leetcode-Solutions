/*
You are given a string s and an array of strings words.

You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words.

If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag.
If two substrings wrapped by bold tags are consecutive, you should combine them.
Return s after adding the bold tags.

Example 1:

Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Explanation: The two strings of words are substrings of s as following: "abcxyz123".
We add <b> before each substring and </b> after each substring.
Example 2:

Input: s = "aaabbb", words = ["aa","b"]
Output: "<b>aaabbb</b>"
Explanation: 
"aa" appears as a substring two times: "aaabbb" and "aaabbb".
"b" appears as a substring three times: "aaabbb", "aaabbb", and "aaabbb".
We add <b> before each substring and </b> after each substring: "<b>a<b>a</b>a</b><b>b</b><b>b</b><b>b</b>".
Since the first two <b>'s overlap, we merge them: "<b>aaa</b><b>b</b><b>b</b><b>b</b>".
Since now the four <b>'s are consecutive, we merge them: "<b>aaabbb</b>".
*/

class Solution {
public:
    string addBoldTag(string s, vector<string> &words) {
        int n = s.size();
        vector<bool> bold(n);

        for (auto word: words) {
            int start = s.find(word);
            while (start != -1) {
                for (int i=start; i<word.size()+start; i++) {
                    bold[i] = true;
                }

                start = s.find(word, start+1);
            }
        }

        for (int i=0; i<n; i++) {
            cout<<bold[i]<<" ";
        }

        string bs = "<b>";
        string be = "</b>";
        string ans = "";

        for (int i=0; i<n; i++) {
            if (bold[i] and (i==0 or !bold[i-1])) {
                ans += bs;
            }

            ans += s[i];

            if (bold[i] and (i==n-1 or !bold[i+1])) {
                ans += be;
            }
        }

        return ans;
    }
};