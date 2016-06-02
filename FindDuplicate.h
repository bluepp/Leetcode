/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/find-the-duplicate-number/
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

/* https://leetcode.com/discuss/92153/share-my-c-solutions-easy-to-understand
/* 1. binary search */


    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), i = 0, counter = 0;
        int left = 1, right = n - 1, mid = 0;

        while (left < right)
        {
            mid = left + (right - left) / 2;

            counter = 0;
            for (i = 0; i < n; ++i)
            {
                if (nums[i] <= mid)
                    ++counter;
            }

            if (counter > mid)
                right = mid;
            else 
                left = mid + 1;
        }

        return left;
    }
    
    
  /* http://keithschwarz.com/interesting/code/find-duplicate/FindDuplicate.python.html */
      int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, finder = 0;

        while (1)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast)
                break;
        }


        while (1)
        {
            finder = nums[finder];
            slow = nums[slow];

            if (finder == slow)
                return finder;
        }
    }
