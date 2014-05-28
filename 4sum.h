/*
 Author:     bluepp
 May the force be with my
 2014-05-28


 Problem:    4Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_18
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

vector<vector<int>> 4Sum(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> res;
    if (n < 4) return res;
    
    sort(num.begin(), num.end());
    
    for (int i = 0; i < n-3; i ++)
    {
        if (i > 0 && num[i] == num[i-1])
            continue;
        
        for (int j = i +1; j < n -2; j++)
        {
            int l = j + 1; 
            int r = n - 1;
            
            if (j > i +1 && num[j] == num[j-1])
                continue;
            int twosum = target - num[i] - num[j];    
            
            while (l < r)
            {
                int sum = num[l] + num[r];
                
                if (sum == twosum)
                {
                    vector<int>tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[l]);
                    tmp.push_back(num[r]);
                    res.push_back(tmp);
                    
                    while (l < r && num[l] == num[l+1])
                        l ++;
                    while(l < r && num[r] == num[r-1])
                        r--;
                        
                    l ++;
                    r--
                    
                }
                else if (sum < twosum)
                    l ++;
                else
                    r --;
                  
            }
            
        }
    }
    
    
}
