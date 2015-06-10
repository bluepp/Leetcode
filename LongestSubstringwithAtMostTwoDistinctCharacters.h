/*
  2015-06-10
  bluepp
  May the force be with me!
  
  Longest Substring with At Most Two Distinct Characters Total Accepted: 2704 Total Submissions: 8893 My Submissions Question Solution 
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is "ece" which its length is 3.

https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

*/

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

