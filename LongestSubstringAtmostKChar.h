/*
bluepp
2016-06-07
May the force be with me!

https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

*/

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
