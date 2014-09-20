/*
 bluepp
 
 2014-05-28
 2014-07-05
 2014-08-03
 2014-08-29
 2014-09-20
 
 May the force be with me!


 Problem:    4Sum
 Difficulty: Medium
 Source:    https://oj.leetcode.com/problems/4sum/
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 Find all unique quadruplets in the array which gives the sum of target.
 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 Solution: Similar to 3Sum, 2Sum.
 */


/* 2014-09-20, my version */

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int n = num.size();
        if (n < 4) return res;
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n-3; i++)
        {
            if (i > 0 && num[i] == num[i-1]) continue;
            
            for (int j = i+1; j < n-2; j++)
            {
                if (j > i+1 && num[j] == num[j-1]) continue;
                
                int l = j+1, r = n-1;
                
                while (l < r)
                {
                    int tmp = num[i]+num[j]+num[l]+num[r];
                    
                    if (tmp == target)
                    {
                        vector<int> vec;
                        
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[l]);
                        vec.push_back(num[r]);
                        
                        res.push_back(vec);
                        
                        while (num[l] == num[l+1]) l++;
                        while (num[r] == num[r-1]) r--;
                        
                        l++;
                        r--;
                    }
                    else if (tmp < target)
                    {
                        l ++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
        
        return res;
    }




    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        int n = num.size();
        if (n < 4) return res;
        sort(num.begin(), num.end());
        
        for (int i = 0; i < n-3; i++)
        {
            if (i > 0 && num[i] == num[i-1]) continue;
            for (int j = i+1; j < n-2; j++)
            {
                if (j > i+1 && num[j] == num[j-1]) continue;
                
                int l = j+1, r = n-1;
                while (l < r)
                {
                    int tmp = num[i] + num[j] + num[l] + num[r];
                    if (tmp == target)
                    {
                        vector<int> vec;
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[l]);
                        vec.push_back(num[r]);
                        res.push_back(vec);
                        
                        while (l > 0 && num[l] == num[l+1]) l++;
                        while (r < n-1 && num[r] == num[r-1]) r--;
                        
                        l++; r--;
                    }
                    else if (tmp < target) l++;
                    else r--;
                }
            }
        }
        
        return res;
        
    }
