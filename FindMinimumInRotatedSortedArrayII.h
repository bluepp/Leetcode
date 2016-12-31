/*
  2014-12-14
  bluepp
  May the force be with me!

https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/  
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

    int findMin(vector<int> &num) {
        int n = num.size();
        
        int l = 0, r = n-1;
        while (l < r && num[l] >= num[r])
        {
            int m = l + (r-l)/2;
            
            if (num[m] > num[r]) l = m+1;
            else if (num[m] <num[l]) r = m;
            else l++;
        }
        
        return num[l];
    }


/* 2016-12-31 */
    int findMin(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int l = 0, r = nums.size()-1;
        int ret = nums[0];
        
        while (l < r-1)
        {
            int m = l + (r-l)/2;
            
            if (nums[l] < nums[m])
            {
                ret = min(ret, nums[l]);
                l = m+1;
            }
            else if (nums[l] > nums[m])
            {
                ret = min(ret, nums[m]);
                r = m;
            }
            else l++;
        }
        
        ret = min(ret, min(nums[l], nums[r]));
        
        return ret;
        
    }
