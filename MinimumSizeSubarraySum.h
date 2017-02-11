/*
  2015-06-16
  bluepp
  May the force be with me!
  
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

https://leetcode.com/problems/minimum-size-subarray-sum/
*/

/* O(N) */
/* 2017-02-12, update */
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int n = nums.size();
        
        int sum = 0;
        int start = 0;
        int ret = n+1;
        
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        
            while (start < i && (sum-nums[start]) >= s)
            {
                sum -= nums[start];
                start++;
            }
                
            if (sum >= s) ret = min(ret, i-start+1);
        
        }
        
        return ret== n+1 ? 0 : ret;
    }


    
    /* O(nlongn) http://www.cnblogs.com/grandyang/p/4501934.html */
     int minSubArrayLen(int s, vector<int>& nums) {
       int len = nums.size(), sums[len + 1] = {0}, res = len + 1;
        for (int i = 1; i < len + 1; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 0; i < len + 1; ++i) {
            int right = searchRight(i + 1, len, sums[i] + s, sums);
            if (right == len + 1) break;
            if (res > right - i) res = right - i;
        }
        return res == len + 1 ? 0 : res;
    }
    
    int searchRight(int left, int right, int key, int sums[]) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (sums[mid] >= key) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
