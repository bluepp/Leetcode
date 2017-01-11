/*
  bluepp
  2014-12-12
  May the force be with me!
  
https://oj.leetcode.com/problems/maximum-gap/  
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/* 2017-01-11, update , bucket sort */

    int maximumGap(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
        
        for (auto p : nums)
        {
            mx = max(mx, p);
            mn = min(mn, p);
        }
        
        int size = (mx-mn)/n + 1;
        int bucket_num = (mx - mn)/size + 1;
        
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_max(bucket_num, INT_MIN);
        
        set<int> s;
        
        for (auto p : nums)
        {
            int idx = (p-mn)/size;
            
            bucket_min[idx] = min(bucket_min[idx], p);
            bucket_max[idx] = max(bucket_max[idx], p);
            
            s.insert(idx);
        }
        
        int pre = 0, res = 0;
        for (int i = 1; i < n; i++)
        {
            if (!s.count(i)) continue;
            
            res = max(res, bucket_min[i]-bucket_max[pre]);
            pre = i;
        }
        
        return res;
    }



/* radix sort */
https://leetcode.com/discuss/53636/radix-sort-solution-in-java-with-explanation


/* bucket sort */
/* https://leetcode.com/discuss/36502/my-concise-and-short-c-code-with-comment-explanation */
/* https://leetcode.com/discuss/18499/bucket-sort-java-solution-with-explanation-o-time-and-space */


int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if( n < 2 ) return 0;
    int maxE = *max_element(nums.begin(),nums.end());
    int minE = *min_element(nums.begin(),nums.end());

    int len = maxE - minE;
    if( len <= 1 ) return len;
    vector<int> buck_max(n, INT_MIN);
    vector<int> buck_min(n, INT_MAX);

    for(int i = 0; i < n; i++) {
        // note the divide and multiply order and the double cast
        // it's used to avoid the overflow and underflow during calculation
        int index = (double)( nums[i] - minE )  / len * ( n - 1 );
        buck_max[index] = max(buck_max[index], nums[i]);
        buck_min[index] = min(buck_min[index], nums[i]);
    }

    int gap = 0, pre = buck_max[0];
    for(int i = 1; i < n; i++) {
        if( buck_max[i] == INT_MIN ) continue;
        gap = max(gap, buck_min[i] - pre);
        pre = buck_max[i];
    }
    return gap;
}





    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int minVal = nums[0], maxVal = nums[0];
        for (int i = 1; i < n; i++)
        {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        
        //delta = (maxVal+1-minVal) / (n+1)
        //index = (val-minVal) / delta = (val-minVal) *(n+1) / (maxVal+1-minVal);
        vector<pair<int, int> > pool(n+2, make_pair(-1, -1));
        for (int i = 0; i < n; i++)
        {
            int index = (long long)(nums[i] - minVal) * (n+1) / (maxVal+1-minVal);
            
            if (pool[index].first == -1)
            {
                pool[index] = make_pair(nums[i], nums[i]);
            }
            else
            {
                pool[index].first = min(pool[index].first, nums[i]);
                pool[index].second = max(pool[index].second, nums[i]);
            }
        }
        
        int last = pool[0].second;
        int ret = 0;
        for (int i = 1; i < n+2; i++)
        {
            if (pool[i].first != -1)
            {
                ret = max(ret, pool[i].first - last);
                last = pool[i].second;
            }
        }
        
        return ret;
    }
