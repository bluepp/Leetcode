/*
  2015-06-10
  2015-08-27, update linear space, version
  bluepp
  May the force be with me!
  
  Longest Substring with At Most Two Distinct Characters Total Accepted: 2704 Total Submissions: 8893 My Submissions Question Solution 
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.

https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

*/

/* 2015-08-27, linear space, update */

    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        char first = '0', second = '0';
        int f_last = -1, s_last = -1;
        
        int ret = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (first == '0')
            {
                first = s[i];
                f_last = i;
            }
            else if (s[i] == first)
            {
                f_last = i;
            }
            else if (second == '0')
            {
                second = s[i];
                s_last = i;
            }
            else if (s[i] == second)
            {
                s_last = i;
            }
            else
            {
                ret = max(ret, i-start);
                
                if (f_last < s_last) 
                {
                    first = s[i];
                    start = f_last+1;
                    f_last = i;
                }
                else
                {
                    second = s[i];
                    start = s_last +1;
                    s_last = i;
                }
            }
        }
        
        ret = max(ret, n-start);
        
        return ret;
    }

/* 2015-09-07, hash */
   int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        unordered_map<char, int> map;
        
        int ret = 0;
        int start = 0;
        char first = '0', second = '0';
        for (int i = 0; i < n; i++)
        {
            if (first == '0') 
            {
                first = s[i];
            }
            else if (s[i] != first && second == '0') 
            {
                second = s[i];
            }
            else if (s[i] != first && s[i] != second)
            {
                if (map[first] < map[second])
                {
                    start = map[first]+1;
                    first = second;
                }
                else
                {
                    start = map[second]+1;
                }
                
                second = s[i];
            }
            
            map[s[i]] = i;
            ret = max(ret, i-start+1);
            
        }
        
        ret = max(ret, n-start);
        return ret;
    }
    




/* 2015-07-22, update, my version */
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if (n < 2) return n;
        
        int ret = 0;
        unordered_map<char, int> map;
        for (int start = 0, end = 0; end < n; end++)
        {
            
            map[s[end]]++;
            
            while (map.size() > 2)
            {
                map[s[start]]--;
                if (map[s[start]] == 0) map.erase(s[start]);
                start++;
            }
            
            ret = max(ret, end-start+1);
        }
        
        return ret;
    }



    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if (n <= 2) return n;
        
        char first = s[0], second = '0';
        int start = 0;
        unordered_map<char, int> map;
        int ret = 0;
        
        for (int i = 1; i < n; i++)
        {
           
           if ((s[i] != first) && (s[i] != second))
           {
               if (second == '0')
               {
                   second = s[i];
               }
               else
               {
                   start = min(map[first], map[second]) + 1;
                   
                   first = (map[first] < map[second]) ? second : first;
                   second = s[i];
               }
           }
           
           map[s[i]] = i;
           ret = max(ret, i-start+1);
           
        }
        
        return ret;
    }

