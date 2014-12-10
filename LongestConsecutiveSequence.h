/*
    bluepp
    
    2014-06-12
    2014-07-15
    2014-12-10
    
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

    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int n = num.size();
        
        for (int i = 0; i < n; i++)
            s.insert(num[i]);
        
        int res = 0;
        for(int i = 0; i < n && !s.empty(); i++)
        {
            if (s.find(num[i]) == s.end()) continue;
            
            int upper = num[i], lower = num[i];
            
            while (s.find(upper+1) != s.end())
                s.erase(upper++);
            while (s.find(lower-1) != s.end())
                s.erase(lower--);
            
            res = max(res, upper-lower+1);    
        }
        
        return res;
    }
