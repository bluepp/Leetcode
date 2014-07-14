/*
	bluepp
	2014-06-10
	2014-07-15
	May the force be with me!
	
	Author:     Annie Kim, anniekim.pku@gmail.com
  	Problem:    Jump Game
 	Source:     https://oj.leetcode.com/problems/jump-game/
 	Notes:
 	Given an array of non-negative integers, you are initially positioned at the first index of the array.
 	Each element in the array represents your maximum jump length at that position.
 	Determine if you are able to reach the last index.
 	For example:
 	A = [2,3,1,1,4], return true.
 	A = [3,2,1,0,4], return false.
 */
 
    bool canJump(int a[], int n) {
        int i = 0, far = 0;
        while (i <= far && far < n)
        {
            far = max(far, i+a[i]);
            i++;
        }
        
        return far >= (n-1);
    }
    
    
  
    /* my verion */
  
    bool canJump(int A[], int n) {

        if (A[0] >= n-1) return true;
        
        int canjump = A[0];
        int j = 0;
        
        while (j <= canjump)
        {
            int tmp = A[j]+j;
            if (tmp >= n-1) return true;
            if (tmp >= canjump) canjump = tmp;
            j++;
        }
        
        return canjump >= n-1;
    }
