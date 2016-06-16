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

/* 2016-06-17, priority_queue */
class mycompare
{
public:
    bool operator()(int &a, int &b)
    {
        return a > b;
    }

};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<int, vector<int>, mycompare> q;
        
        for (auto p : nums)
        {
            q.push(p);
            
            if (q.size() > k)
            {
                q.pop();
            }
        }
        
        return q.top();
    }

};


/* -------------------------------------------------------------- */


/* quick sort, O(N) average */
/* https://leetcode.com/discuss/38336/solutions-partition-priority_queue-multiset-respectively */

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (true)
        {
            int pos = partition(nums,l, r);
            
            if (pos == k-1) return nums[pos];
            if (pos > k-1) r = pos-1;
            else l = pos+1;
        }
    }
    
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int l = left+1, r = right;
        while (l <= r)
        {
            if (nums[l] < pivot && pivot < nums[r]) swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }



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
