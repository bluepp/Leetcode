/* 2014-05-27 */
/* Author bluepp */
/* May the force be with me */

/* 
Source:     http://leetcode.com/onlinejudge#question_16 

Notes:
 Given an array  S of n integers, find three integers in S such that the sum is closest to 
 a given number, target. Return the sum of the three integers. 
 You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 Solution: Similar to 3Sum, taking O(n^2) time complexity.
 */
 
 int 3SumCloset(vector<int> &num, int target)
 {
      int n = num.size();
      sort(num.begin(), num.end());
      
      int tt = INT_MAX;
      
      for (int i = 0; i < n-2; i ++)
      {
          int k = i + 1, j = n-1;
          
          while(k < j)
          {
              int t = num[i] + num[j] + num[k];
              int abst = abs(t -target);
              
              if (t == target)
                  return target;
              else if (t > target)
                  j --;
              else
                  k ++;
              
              if (t = INT_MAX || abs(t - target) < abs(tt-target)
                  tt = abs(t-target);
              
          }
      }
      
      return tt;
 }
