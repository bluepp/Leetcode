/*
bluepp
2016-12-31
May the force be with me!

https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if (k == 0) return 0;
        
        int ret = 0;
        int start = 0;
        
        unordered_map<char, int> map;
        
        for (int i = 0; i < s.length(); i++)
        {
            map[s[i]] ++;
            
            while (start < i && map.size() > k)
            {
                map[s[start]]--;
                if (map[s[start]] == 0) map.erase(s[start]);
                start ++;
            }
            
            ret = max(ret, i-start+1);
        }
        
        return ret;
    }
    
    
