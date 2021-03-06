/*
bluepp
2017-01-06
May the force be with me!

https://leetcode.com/problems/split-array-largest-sum/

Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Note:
If n is the length of array, assume the following constraints are satisfied:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

    int splitArray(vector<int>& nums, int m) {
        
        int sum = 0, maxv = INT_MIN;
        
        for (auto p : nums)
        {
            sum += p;
            maxv = max(maxv, p);
        }
        
        int l = maxv, r = sum;
        
        while (l < r)
        {
            int mid = l + (r-l)/2;
            
            if (can_split(nums, m, mid)) 
            {
                r = mid;
            }
            else l = mid+1;
        }
        
        return l;
    }
    
    
    bool can_split(vector<int>& nums, int m, int sum) {
        
        int cnt = 1, curSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                ++cnt;
                if (cnt > m) return false;
            }
        }
        
        return true;
    }
