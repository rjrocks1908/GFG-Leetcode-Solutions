//Approach 1: Sorting and Min Heap
/*
Question-
https://leetcode.com/problems/number-of-flowers-in-full-bloom/

Intuition-
We will first sort people and flowers. Flowers should be sorted according to the starting time of bloom.
Because we want to know how many flowers are blooming when a person arrives, we will use a min heap to store the end time of flowers.
We use pointer i to iterate along flowers. For a given person, we find all the flowers that started blooming before person
arrives. We push the end time of these flowers onto a heap. We can then remove all the flowers that have already ended blooming before
person arrives. As we sort both input arrays, flowers that we pop from heap will never be seen again by future people.

Implementation-
1. Sort flowers. Create a sorted version of people array which is speople.
2. Create a min heap mheap and a map mp and initialize i = 0.
3. Iterate over speople. While i < flowers.size() and flowers[i][0] <= person, push flowers[i][1] onto mheap and increment i.
4. While mheap is not empty and mheap.top() < person, pop from mheap.
5. Set mp[person] = mheap.size().
6. Iterate over people and push mp[person] onto ans.

Complexities-
TC: O(nlogn + m(logn + logm))
SC: O(n + m)
*/

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> speople(people.begin(), people.end());
        sort(speople.begin(), speople.end());
        sort(flowers.begin(), flowers.end());

        unordered_map<int,int> mp;
        priority_queue<int, vector<int>, greater<int>> mheap;

        int i=0;
        for (auto person: speople) {
            while (i < flowers.size() and flowers[i][0] <= person) {
                mheap.push(flowers[i][1]);
                i++;
            }

            while (!mheap.empty() and mheap.top() < person) {
                mheap.pop();
            }

            mp[person] = mheap.size();
        }

        vector<int> ans;
        for (auto person: people) {
            ans.push_back(mp[person]);
        }

        return ans;
    }
};

//Approach 2: Binary Search
/*
Intuition-
We will be using a technique called line sweep. In this technique we create a difference array which stores
change in the number of flowers we can see when we cross the array, in simple it can easily tell which index has
how many flowers blooming at that time. So to create this difference array we perform difference[start]++ and difference[end+1]--.
But here the conditions are too large that is 10^9 so we will be using a map to store the difference array. Along with this 
we will also store the prefix sum of the difference array in a vector and the positions of the difference array in another vector.
Now with the help of binary search we find the upper_bound of the given person in the positions vector and then we subtract 1 from it.
Please refer to the editorial of the problem statement for graphic representation.

Implementation-
1. Initialize a sorted-map data structure difference with 0: 0.
2. Iterate over each flower = [start, end] in flowers: Increment difference[start]. Decrement difference[end + 1].
3. Initialize two arrays, positions and prefix. Iterate over the keys of difference: 
    -positions contains all the keys in the order they are traversed.
    -prefix contains the prefix sum of the corresponding values.
4. Initialize the answer array ans. Iterate over each person in people:
    -Perform a right-insertion index binary search on positions with person.
    -Calculate i as the result of this binary search minus one.
    -Add prefix[i] to ans.
5. Return ans.

Complexities-
TC: O(nlogn + mlogn)
SC: O(n)
*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int> diff;
        diff[0] = 0;

        for (auto flower: flowers) {
            diff[flower[0]]++;
            diff[flower[1]+1]--;
        }

        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto pair: diff) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }

        vector<int> ans;
        for (auto person: people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin();
            int idx = i-1;
            ans.push_back(prefix[idx]);
        }

        return ans;

    }
};

//Approach 3: Simpler Binary Search
/*
Intuition-
The idea behind this strategy is that at any given time, the number of flowers we see is the number of flowers that have 
already started blooming minus the amount of flowers have finished blooming.

Is there a simpler way to identify at a given time, how many flowers have started blooming, 
and how many flowers have finished blooming? In the first two approaches, we always associate the start and end of the same 
flower together for processing, which is more intuitive but can be more complex to handle. 
What if we separately consider these two sets of times?
We can simply collect all start points in one array starts, sort it, and then perform a binary search. 
We can do the exact same thing with another array ends for all end points.

Implementation-
1. Create 2 arrays starts and ends
2. Iterate over flowers and push flower[0] and flower[1]+1 onto starts and ends respectively.
3. Sort bothe arrays
4. Iterate over people and perform a right-insertion index binary search on starts and ends with person.
5. Calculate i and j and push i-j onto ans.

Complexities-
TC: O((n+m)logn)
SC: O(n)
*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;

        for (auto flower: flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1]+1);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        vector<int> ans;

        for (auto person: people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i-j);
        }

        return ans;

    }
};