/*
	bluepp	
	
	2014-06-05
	2014-07-09
	2014-08-12
	2014-09-06
	
	May the force be with me!
	
	Problem:    Container With Most Water

 	Source:     https://oj.leetcode.com/problems/container-with-most-water/
 	Notes:
 	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 	Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 	Note: You may not slant the container.

 	Solution: From both sides to the center.
*/

    int maxArea(vector<int> &height) {
         int n = height.size();
         
         int l = 0, r = n-1;
         int area = 0;
         
         while (l < r)
         {
             if (height[l] <= height[r])
             {
                 area = max(area, height[l] * (r-l));
                 l++;
             }
             else
             {
                 area = max(area, height[r]*(r-l));
                 r--;
             }
         }
         
         return area;
    }
