/*
  2015-08-18
  bluepp
  May the force be with me!
  
Given an array of n integers nums and a target, find the number of index triplets i, j, k
with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
Follow up:
Could you solve it in O(n2) runtime?

https://leetcode.com/problems/3sum-smaller/
*/

/* https://leetcode.com/discuss/52362/11-lines-o-n-2-python */
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (int i = 0; i < n-2; i++)
        {
            int l = i+1, r = n-1;
            while (l < r)
            {
                int t = nums[i] + nums[l] + nums[r];
                if (t < target)
                {
                    ret += r-l;
                    l++;
                }
                else r--;
            }
        }
        
        return ret;
    }
