/*
bluepp
2016-06-07
May the force be with me!

https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

*/


/* 2017-01-03, update */
   int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if (k == 0) return 0;
        
        int n = s.length();
        int ret = 0;
        int start = 0;
        unordered_map<char, int> map;
        
        for (int i = 0; i < n; i++)
        {
            map[s[i]]++;
            
            while (start < i && map.size() > k)
            {
                map[s[start]]--;
                if (map[s[start]] == 0)
                {
                    map.erase(s[start]);
                }
                start ++;
            }
            
            ret = max(ret, i-start+1);
        }
        
        return ret;
   
    }


/* 2017-01-03, another one, map[s[i]] = i */

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > k) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }





/* 1. my versioin , 2.template */

/* 2016-06-14 , update, my version */

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        unordered_map<char, int> map;
        int start = 0;
        int ret = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            map[s[i]]++;
            
            int j = 0;
            
            if (map.size() > k)
            {
                for (j = start; j <= i; j++)
                {
                    map[s[j]]--;
                    
                    if (map[s[j]] == 0) 
                    {
                        map.erase(s[j]);
                        start = j+1;
                        break;
                    }
                }
            }
            
            ret = max(ret, i-start+1);
            
        }
        
        return ret;
       
    }



//template
/* https://leetcode.com/discuss/72701/here-10-line-template-that-can-solve-most-substring-problems*/

   int lengthOfLongestSubstringKDistinct(string s, int k) {
       if (s.empty() || k <= 0)    
        {
            return 0;
        }

        unordered_map<char, int> map;
        int start = 0;
        int end = 0;
        int count = 0;  // the count number of distinct chars
        int maxLen = 0;

        while(end < s.size())
        {
            if (map[s[end++]]++ == 0)
            {
                count++;
            }
            
             while(count > k)
            {
                if (map[s[start++]]-- == 1)
                {
                    count--;
                }
            }

            maxLen = max(maxLen, end - start);
        }


        return maxLen;
    }
