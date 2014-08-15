/* 
	bluepp
	2014-06-11
	2014-07-15
	2014-08-15
	May the force be with me!
	
 	Problem:    Largest Rectangle in Histogram
 	Source:     https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
 	Notes:
 	Given n non-negative integers representing the histogram's bar height where the width of each 
 	bar is 1, find the area of largest rectangle in the histogram.
 	For example,
 	Given height = [2,1,5,6,2,3],
 	return 10.

 	Solution: 1. Only calucate area when reaching local maximum value.
              2. Keep a non-descending stack. O(n).
*/

/* haixiao yang, http://haixiaoyang.wordpress.com/?s=rectangle */
    int largestRectangleArea(vector<int> &height) {
       int res = 0;
       int n = height.size();
       stack<int> s;
       
       for (int i = 0; i <= n; i++)
       {
           int curr = (i == n) ? INT_MIN:height[i];
           
           while (!s.empty() && curr < height[s.top()])
           {
               int h = height[s.top()];
               s.pop();
               int w = s.empty() ? i : i-s.top()-1;
               res = max(res,h*w);
           }
           
           s.push(i);
        
       }
       
       return res;
    }
    
    
    



int largestRectangleArea(vector<int> &height) {
        
        height.push_back(0); -------------------------------->>>>>>>>>>>>>>>>!!!!!
        int n = height.size();
        stack<int> s;
        int i = 0, res = 0;
        
        while(i < n)
        {
            if (s.empty() || height[s.top()] <= height[i])
            {
                s.push(i);
                i++;
            }
            else
            {
                int h = s.top(); s.pop();
                int w = s.empty() ? i : (i-s.top()-1);
                res = max(res, height[h]*w);
            }
        }
        
        return res;
    }
