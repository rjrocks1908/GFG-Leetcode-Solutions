/*
Intuition - 
To find exactly k unique characters of substringsk, we need to find the
substrings which has at most k unique characters and then we will substract the
k-1 unique characters substring. To find the above solutions we will be using the
sliding window technique.

Implementation -
We keep a count for total number of substrings which has the k at most unique characters.
In sliding window two pointers will be there one is "i" and other is "idx" and we will maintain a
array of size 26 to check that the substring we select has atmost k unique characters.

We keep on incrementing the "i" untill we find k unique characters and then from idx to i we will
add all the substring. "idx" will only move when unique characters become greater than k.
*/

class Solution
{
  public:
    long long int solve (string s, int k) {
    
        int size = 0;
        int n = s.size();
        long long int count = 0;
        vector<int> arr(26, 0);
        int idx=0;
        
        for (int i=0; i<n; i++) {
        
            char ch = s[i];
            if (arr[ch-'a'] == 0)
                size++;
            
            arr[ch-'a']++;
            
            //Decreasing the window size
            while (size > k) {
                
                char c = s[idx];
                arr[c-'a']--;
                if (arr[c-'a'] == 0) {
                    size--;
                }
                
                idx++;
                
            }
        
            count += (i-idx+1);
        
        }
        
        return count;
    
    }
  
    long long int substrCount (string s, int k) {
    	//code here.
    	return solve(s,k) - solve(s,k-1);
    	
    }
};