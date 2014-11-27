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
