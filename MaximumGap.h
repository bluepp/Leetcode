/*
  bluepp
  2014-12-12
  May the force be with me!
  
https://oj.leetcode.com/problems/maximum-gap/  
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*https://algnotes.wordpress.com/2012/07/22/the-maximum-gap-problem/ */
/* Runtime error */
{
    int min;
    int max;
    
    range():min(-1),max(-1) {};
};

class Solution {
public:
    int maximumGap(vector<int> &num) {
        
        int n = num.size();
        if (n < 2) return 0;
        
        int minval = num[0], maxval = num[0];
        for (int i = 0; i < n; i++)
        {
            if (num[i] < minval) minval = num[i];
            if (num[i] > maxval) maxval = num[i];
        }
        
        int d = (maxval-minval)/(n-1);
        range ra[n];
        
        for (int i = 0; i < n; i++)
        {
            int t = (num[i]-minval)/d;
           
            ra[t+1].min = (ra[t+1].min == -1) ? num[i] : min(ra[t+1].min, num[i]);
            ra[t+1].max = (ra[t+1].max == -1) ? num[i] : max(ra[t+1].max, num[i]);
            
        }
        
        int bef_val = ra[0].max;
        int ret = 0;
        
        for (int i = 1; i < n-1; i++)
        {
            if (bef_val == -1 || ra[i].min == -1 || ra[i].max == -1) continue;
            
            ret = max(ret, ra[i].min-bef_val);
            bef_val = ra[i].max;
        }
        
        return ret;
    }
};
