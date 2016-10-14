/* 
2016-10-15
bluepp
May the force be with me!

https://leetcode.com/problems/intersection-of-two-arrays-ii/

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ret;
        unordered_map<int, int> map;
        
        for (auto p : nums1)
        {
            map[p]++;
        }
        
        for (auto p : nums2)
        {
            if (map.count(p) && map[p] > 0)
            {
                ret.push_back(p);
                map[p]--;
                if (map[p] == 0) map.erase(p);
            }
        }
        
        return ret;
  
    }
