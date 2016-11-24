/*
bluepp
2016-11-24
May the force be with me!

https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

    int minMoves(vector<int>& nums) {
        
        int mn = INT_MAX, ret = 0;
        
        for (auto p : nums)
        {
            mn = min(mn, p);
        }
        
        for (auto p : nums)
        {
            ret += p - mn;
        }
        
        return ret;
        
    }
