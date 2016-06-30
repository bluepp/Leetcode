/*
bluepp
2016-06-30
May the force be with me!

https://leetcode.com/problems/intersection-of-two-arrays/

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

*/

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s (nums1.begin(), nums1.end()), res;
        
        for (auto p : nums2)
        {
            if (s.count(p))
            {
                res.insert(p);
            }
        }
        
        return vector<int>(res.begin(), res.end());
    }
