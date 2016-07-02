/*
  2015-09-14
  bluepp
  May the force be with me!
  
Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
https://leetcode.com/problems/wiggle-sort/
*/

/* 2016-06-10 update */
   void wiggleSort(vector<int>& nums) {
       
       int n = nums.size();
       
       for (int i = 0; i < n-1; i++)
       {
           if (i%2 == 0 && nums[i] > nums[i+1])
           {
               swap(nums[i], nums[i+1]);
           }
           
           if (i%2 == 1 && nums[i] < nums[i+1])
           {
               swap(nums[i], nums[i+1]);
           }
       }
       
    }

/* ------------------- */

/* 2016-07-02, with sort */

    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        if (n <= 2)
        {
            return;
        }
        
        for (int i = 2; i < n; i += 2)
        {
            swap(nums[i], nums[i-1]);
        }
    }
    
    



    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        
        bool flag = true;
        int curr = nums[0];
        
        for (int i = 0; i < n-1; i++)
        {
            if ((flag && curr > nums[i+1]) || (!flag && curr < nums[i+1]))
            {
                nums[i] = nums[i+1];
            }
            else
            {
                nums[i] = curr;
                curr = nums[i+1];
            }
            
            flag = !flag;
        }
        
        nums[n-1] = curr;
    }
