/*
  2015-06-15
  bluepp
  May the force be with me!
  
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

https://leetcode.com/problems/kth-largest-element-in-an-array/

*/

/* quick sort, O(N) average */
/* https://leetcode.com/discuss/38336/solutions-partition-priority_queue-multiset-respectively */


    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<int> q;
        
        for (int i = 0; i < n; i++)
        {
            q.push(nums[i]);
        }
        
        int ret = 0;
        for (int i = 0; i < k; i++)
        {
            ret = q.top();
            q.pop();
        }
        
        return ret;
    }
