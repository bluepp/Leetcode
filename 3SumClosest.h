/* bleupp */
/* 2014-05-27 */
/* 2014-07-05 */
/* 2014-08-03 */
/* May the force be with me */

/* 
Source:     https://oj.leetcode.com/problems/3sum-closest/

Notes:
 Given an array  S of n integers, find three integers in S such that the sum is closest to 
 a given number, target. Return the sum of the three integers. 
 You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 Solution: Similar to 3Sum, taking O(n^2) time complexity.
 */
 
 int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        sort(num.begin(), num.end());
        int min_diff = INT_MAX; int res = INT_MAX;
        
        for (int i = 0; i < n-2; i++)
        {
            int l = i+1, r = n-1;
            
            while (l < r)
            {
                int tmp = num[i] + num[l] + num[r];
                
                if (tmp == target) return target;
                else if (tmp < target) l++;
                else r--;
               
                int diff = abs(target - tmp);
                if (diff < min_diff)
                {
                    min_diff = diff;
                    res = tmp;
                }
                 
            }
        }
        
        return res;
    }
