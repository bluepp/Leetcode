/*
    bluepp
    
    2014-06-12
    2014-07-15
    2014-09-06
    2014-09-23
    2014-10-21
    2014-11-23
    2014-12-08
    2014-12-23
    
    May the force be with me!
    
    Problem:    Longest Substring Without Repeating Characters
    Source:     https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
    Notes:
    Given a string, find the length of the longest substring without repeating characters. 
    For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
    For "bbbbb" the longest substring is "b", with the length of 1.

    Solution: Pay attention when moving the 'start' pointer forward.
 */
 

/* 2016-12-31, update, hashtable */

   int lengthOfLongestSubstring(string s) {
       
        int n = s.length();
        unordered_map<char, int> map;
        int start = 0;
        int ret = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (map.count(s[i]))
            {
                start = max(start, map[s[i]]+1);
      
            }
            
            map[s[i]] = i;
            
            ret = max(ret, i-start+1);
        }
        
        return ret;
       
    }




 /* 2016-06-14, update another way */
 /* https://leetcode.com/discuss/13336/shortest-o-n-dp-solution-with-explanations */
 
     int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        vector<int> map(256, -1);
        int start = 0;
        int ret = 0;
        
        for (int i = 0; i < n; i++)
        {
            start = max(start, map[s[i]]+1);
            map[s[i]] = i;
            
            ret = max(ret, i-start+1);
        }
        
        return ret;
    }
 
 
 
 /* 2015-08-27, update */
     int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        unordered_map<char, int> map;
        
        int ret = INT_MIN;
        int start = 0, end = 0;
        
        for (; end < n; end++)
        {
            if (map.count(s[end]))
            {
                ret = max(ret, end-start);
                int t = map[s[end]];
                
                for (int i = start; i <= t; i++)
                {
                    map.erase(s[i]);
                }
                
                start = t+1;
            }
            
            map[s[end]] = end;
        }
        
        ret = max(ret, end-start);
        return ret;
    }
 
 
 
 /* 2014-12-28 */
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        bool exist[256];
        memset(exist, false, sizeof(exist));
        
        int ret = 0;
        int start = 0, end = 0;
        for (; end < n; end++)
        {
            if (exist[s[end]] == 0)
            {
                exist[s[end]] = true;
                ret = max(ret, end-start+1);
            }
            else
            {
                for (; s[start] != s[end]; start++)
                {
                    exist[s[start]] = false;
                }
                
                start ++;
            }
        }
        
        return ret;
    }
 
 
 
 
 
    int lengthOfLongestSubstring(string s) {
        bool exist[256];
        memset(exist, false, sizeof(exist));
        int count = 0;
        
        int start = 0, end = 0;
        int n = s.size();
        while (end < n && start + count < n)
        {
            if (!exist[s[end]])
            {
                exist[s[end]] = true;
                end ++;
            }
            else
            {
                exist[s[start]] = false;
                start ++;
            }
            
            count = max(count, end-start);
        }
        
        return count;
        
    }
