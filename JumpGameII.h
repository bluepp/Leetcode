/*
    bluepp
    
    2014-06-10
    2014-07-15
    2014-08-14
    2014-09-07
    2014-09-21
    2014-10-16
    2014-11-27
    
    May the force be with me!
    
    
    Problem:    Jump Game II
    Source:     https://oj.leetcode.com/problems/jump-game-ii/
    Notes:
    Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Your goal is to reach the last index in the minimum number of jumps.
    For example:
    Given array A = [2,3,1,1,4]
    The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

    Solution: Jump to the position where we can jump farthest (index + A[index]) next time.
 */


/* 2017-03-07, update */
 
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0, start = 0;
        
        while (start < n-1)
        {
            count ++;
            int far = start + nums[start];
            if (far >= n-1) return count;
            
            int max = start;
            for (int i = start+1; i <= far; i++)
            {
                if (nums[i]+i > nums[max]+max) max = i;
            }
            
            start = max;
        }
        
        return count;
    }



/* 2017-01-11, update */

    int jump(vector<int>& nums) {
        
        int steps = 0;
        int curr_far = 0, far = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++)
        {
            if (i > far)
            {
                steps++;
                
                far = curr_far;
                if (curr_far >= n-1) break;
            }
            
            curr_far = max(curr_far, i+nums[i]);
        }
        
        return steps;
      
    }



 
/* 2016-06-12, pass */
/* https://leetcode.com/discuss/95897/my-very-simple-c-solution */
 
 
     int jump(vector<int>& nums) {
       
        int steps = 0, s1 = 0, s2 = 0;// take steps can reach s1, take steps+1 can reach s2
        for (int i = 0; i < nums.size(); ++i) {
        
            if (s1 >= nums.size()-1) return steps;
        
            s2 = max(nums[i]+i,s2);
            if (i >= s1) {//steps is not enough, update s1 to s2 and increase steps
        
                s1 = s2;
                steps++;
            }
        }
        
        return steps;
    }
 
 
 
 /* 2016-06-12 TLE */
    int jump(vector<int>& nums) {
       
       int n = nums.size();
       int count = 0;
       int start = 0;
       
       while (start < n-1)
       {
           count++;
           int far = nums[start]+start;
           if (far >= n-1) return count;
           
           int max = start;
           for (int j = start+1; j <= far; j++)
           {
               if (j+nums[j] > start+nums[start]) max = start;
           }
           
           start = max;
       }
       
       return count;
       
    }
 
 
    int jump(int A[], int n) {
        int count = 0;
        int start = 0;
        
        while (start < n-1)
        {
            count ++;
            int far = start + A[start];
            if (far >= n-1) return count;
            
            int max = start;
            for (int i = start+1; i <= far; i++)
            {
                if (A[i]+i > A[max]+max) max = i;
            }
            
            start = max;
        }
        
        return count;
        
    }
