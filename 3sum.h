/* 2014 05 26 */
/* 2014-07-05 */
/* 2014-08-03 */
/* 2014-12-05 */
/* May the force be with me */

/*
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 
 source : https://oj.leetcode.com/problems/3sum/
 
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 Solution: Simplify '3sum' to '2sum' O(n^2). http://en.wikipedia.org/wiki/3SUM
 */
 
 
 /* 2015-08-13, update, vec = {} */
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;
        int n = num.size();
        if (n < 3) return res;
        
        sort (num.begin(), num.end());
        
        for (int i = 0; i < n-2; i++)
        {
            if (i > 0 && num[i] == num[i-1]) continue;
            
            int l = i+1, r = n-1;
            while (l < r)
            {
                vector<int> vec;
                int t = num[i]+num[l]+num[r];
                
                if (t == 0)
                {
                    
                    vec = {num[i], num[l], num[r]};
                    
                    l++;
                    r--;
                    
                    while (l < r && num[l] == num[l-1]) l++;
                    while (l < r && num[r] == num[r+1]) r--;
                }
                else if (t < 0) l++;
                else r--;
                
                if (vec.size() != 0)
                {
                    res.push_back(vec);
                }
            }
        }
        
        return res;

    }
 
