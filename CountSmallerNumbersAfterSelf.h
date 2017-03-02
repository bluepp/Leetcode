/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/count-of-smaller-numbers-after-self/

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/



/* 2017-03-02, update, lllll? */

    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n), t;
        
        for (int i = n-1; i >= 0; i--)
        {
            int l = 0, r = t.size();
            
            while (l < r)
            {
                int m = l + (r-l)/2;
                if (t[m] >= nums[i]) r = m;
                else l = m+1;
            }
            
            res[i] = l;
            t.insert(t.begin()+l, nums[i]);
        }
        
        return res;
    }


/* 2017-01-04, update, binary search */
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n);
        vector<int> t;
        
        for (int i = n-1; i >= 0; i--)
        {
            int l = 0, r = t.size();
            
            while (l < r)
            {
                int m = l + (r-l)/2;
                
                if (t[m] >= nums[i])
                {
                    r = m;
                }
                else l = m+1;
            }
            
            res[i] = r;
            t.insert(t.begin()+r, nums[i]);
        }
        
        return res;
    }






/* https://leetcode.com/discuss/79463/segment-binary-indexed-binary-search-tree-clean-python-code */


/* O(N2) */
    vector<int> countSmaller(vector<int>& nums) {
        
        if (nums.empty()) return {};
        
        int n = nums.size();
        vector<int> hash;
        vector<int> counts(n, 0);
        
        for (int i = n-1; i >= 0; i--)
        {
            auto end = lower_bound(hash.begin(), hash.end(), nums[i]);
            counts[i] = end - hash.begin();
            hash.insert(end, nums[i]);
        }
        
        return counts;
    }
