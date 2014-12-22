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
 
 /* 2014-12-08, my version */
 /* waste memory, int, and not dp, should use old version */
 
     int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int dp[256];
        memset(dp, 0, sizeof(dp));
        int ret = 0;
        
        for (int start = 0, end = 0; end < n; end ++)
        {
            if (dp[s[end]] == 0) 
            {
                dp[s[end]]++;
                ret = max(ret, end-start+1);
            }
            else
            {
                
                for (; s[start] != s[end]; start++)
                {
                    dp[s[start]] = 0;
                }
                
                start++;
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
