/*
    bluepp
    
    2014-06-12
    2014-07-15
    2014-12-10
    2014-12-22
    
    May the force be with me!
    
    Problem:    Longest Consecutive Sequence
    Source:     https://oj.leetcode.com/problems/longest-consecutive-sequence/
    Notes:
    Given an unsorted array of integers, find the length of the longest consecutive 
    elements sequence.
    For example,
    Given [100, 4, 200, 1, 3, 2],
    The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
    Your algorithm should run in O(n) complexity.

    Solution: Update solution. This solution is from Peking2 (http://blog.sina.com.cn/s/blog_b9285de20101iqar.html).
              This solution is much easier to understand.
*/

/* 2016-12-31, update */
    int longestConsecutive(vector<int>& nums) {
        
        int ret = 0;
        
        unordered_set<int> set (nums.begin(), nums.end());
        
        for (auto p : nums)
        {
            if (!set.count(p)) continue;
            
            set.erase(p);
            int pre = p-1, next = p+1;
            while (set.count(pre)) set.erase(pre--);
            while (set.count(next)) set.erase(next++);
            
            ret = max(ret, next-pre-1);
        }
        
        return ret;
        
    }


/* another one */
    int longestConsecutive(vector<int>& nums) {
        
        int ret = 0;
        unordered_map<int, int> map;
        
        for (auto p : nums)
        {
            if (!map.count(p))
            {
                int l = map.count(p-1) ? map[p-1] : 0;
                int r = map.count(p+1) ? map[p+1] : 0;
                
                int sum = l+r+1;
                map[p] = sum;
                ret = max(ret, sum);
                
                map[p-l] = sum;
                map[p+r] = sum;
            }
        }
        
        return ret;
        
    }









/* 2016-06-26 , unordered_map */
   int longestConsecutive(vector<int>& nums) {
        
        int ret = 0;
        unordered_map<int, int> map;
        
        
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            int d = nums[i];
            int n = 1;
            
            map.erase(d);
            while (map.find(++d) != map.end())
            {
                n++;
                map.erase(d);
            }
            
            d = nums[i];
            while (map.find(--d) != map.end())
            {
                n++;
                map.erase(d);
            }
            
            ret = max(ret, n);
        }
        
        return ret;
    }


    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int n = num.size();
        
        for (int i = 0; i < n; i++)
            s.insert(num[i]);
        
        int res = 0;
        for(int i = 0; i < n && !s.empty(); i++)
        {
//            if (s.find(num[i]) == s.end()) continue;  2014-12-10
            
            int upper = num[i], lower = num[i];
            
            while (s.find(upper+1) != s.end())
                s.erase(upper++);
            while (s.find(lower-1) != s.end())
                s.erase(lower--);
            
            res = max(res, upper-lower+1);    
        }
        
        return res;
    }
