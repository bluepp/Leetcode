/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/increasing-triplet-subsequence/
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/


/* 2016-10-17, update */
    bool increasingTriplet(vector<int>& nums) {
        
        int m1 = INT_MAX, m2 = INT_MAX;
        
        for (auto p : nums)
        {
            if (m1 >= p) m1 = p;
            else if (m2 >= p) m2 = p;
            else return true;
        }
        
        return false;
     
    }
