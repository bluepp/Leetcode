/* 2014 05 26 */
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
 
 /* do not consider duplicates */
 /* will figure it out */
 
 
 vector<vector<int>> 3sum(vector<int> &num)
 {
    vector<vector<int>> res;
    int n = num.size();
    sort(num.begin(), num.end());
    
    for (int i = 0; i < n-2; i ++)
    {
        int j = i + 1, k = n - 1;
        
        while (j < k)
        {
            int t = num[i] + num[j] + num[k];
            
            if (t == 0)
            {
                vector<int> triple;
                triple.push_back(num[i]);
                triple.push_back(num[j]);
                triple.push_back(num[k]);
                res.push_back(triple);
                j ++; k --;
            }
            else if (t > 0)
            {
                j ++;
            }
            else
                k --;
        }
    }
 }
 
