/*
Question -
https://leetcode.com/problems/majority-element-ii/

Intuition -
Store the frequencies in a hash map and then find all the elements
whose frequencies is greater than n/3

Complexities -
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        int range = n/3;
        vector<int> ans;
        for (auto x:mp) {
            if (x.second > range) {
                ans.push_back(x.first);
            }
        }

        return ans;

    }
};


Approach-2
/*
Intuition-
We already know that atmost 2 candidates appears more than n/3 according to the Boyer-Moore Majority vote Algorithm.
We take 2 candidates "cand1" and "cand2".

Implementation-
First We initialize two candidate variables, cand1 and cand2, to 0, and two count variables, cnt1 and cnt2, to 0.
These variables will keep track of the current potential majority elements and their counts.

We iterate through the nums array in the first pass. For each element num, we do the following:

1. If num is the same as candidate1, we increment count1 because we found another occurrence of candidate1.
2. Else if num is the same as candidate2, we increment count2 because we found another occurrence of candidate2.
3. If count1 is 0, we assign num to candidate1 and set count1 to 1, indicating that num is the current potential majority candidate.
4. If count2 is 0, we assign num to candidate2 and set count2 to 1, indicating that num is the current potential majority candidate.
5. If num is neither candidate1 nor candidate2, we decrement both count1 and count2 because we have found a pair of distinct elements,
   and we can eliminate them as potential majority elements.
6. After the first pass, candidate1 and candidate2 represent the two potential majority candidates.

In the second pass through the nums array, we count the actual occurrences of candidate1 and candidate2 
to verify if they indeed appear more than ⌊n/3⌋ times.

Finally, we add candidate1 and candidate2 to the answer vector if their counts are greater than ⌊n/3⌋.

Complexities-
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int cand1=0, cand2=0, cnt1=0, cnt2=0;
        int n=nums.size();
        for (int i=0; i<n; i++) {
            if (cand1 == nums[i]) cnt1++;
            else if (cand2 == nums[i]) cnt2++;
            else if (cnt1 == 0) { 
                cand1 = nums[i];
                cnt1=1;
            } else if (cnt2 == 0) {
                cand2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1=0, cnt2=0;
        for (int i=0; i<n; i++) {
            if (nums[i] == cand1) {
                cnt1++;
            }
            if (nums[i] == cand2) {
                cnt2++;
            }
        }
        vector<int> ans;
        if (cnt1 > n/3) ans.push_back(cand1);
        if (cnt2 > n/3 and cand1 != cand2) ans.push_back(cand2);

        return ans;

    }
};