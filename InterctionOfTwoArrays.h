/*
bluepp
2016-06-01
May the force be with me!

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

https://leetcode.com/problems/intersection-of-two-arrays/
*/

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;
        
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 == 0 || n2 == 0) return res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (nums1[i] < nums2[j])
            {
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                if (res.empty() || res.back() != nums1[i])
                {
                    res.push_back(nums1[i]);
                }
                
                i++;
                j++;
            }
        }
        
        return res;
    }

