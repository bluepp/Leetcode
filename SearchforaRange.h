/*
    bluepp
    2014-06-22
    May the force be with me!
    
 Problem:    Search for a Range
 Source:     https://oj.leetcode.com/problems/search-for-a-range/
 Notes:
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Solution: It takes O(lgN) to find both the lower-bound and upper-bound.
 */
 
 
/* There is another solution */ 
/* My solution, not logn? */ 
  vector<int> searchRange(int a[], int n, int target) {
        vector<int> res;
        
        int l = 0, r = n-1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            
            if (a[m] == target)
            {
                int ll = m, rr = m;
                while (ll > l && a[ll] == target)
                {
                    ll--;
                }
                while (rr < r && a[rr] == target)
                {
                    rr ++;
                }
                
                if (a[rr] != target)
                    rr--;
                if (a[ll] != target)
                    ll++;
                
                res.push_back(ll);
                res.push_back(rr);
                return res;
            }
            
            if (a[m] < target)
                l ++;
            else
                r --;
        }
        
        res.push_back(-1);
        res.push_back(-1);
        
        return res;
        
    }
