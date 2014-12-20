/*
  2014-12-21
  bluepp
  May the force be with me!
  
Longest Substring with At Most Two Distinct Characters Total Accepted: 515 Total Submissions: 

Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,
T is "ece" which its length is 3.

*/


    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        if (n < 2) return n;
        
        int maxlen = 1;
        int diffindex = -1; /* first different char from right to left */
        int currlen = 1;
        int maxstart = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i-1])
            {
                if (diffindex == -1 || s[i] == s[diffindex])
                {
                    currlen ++;
                }
                else 
                {
                    currlen = i - diffindex;
                }
                
                diffindex = i-1;
            }
            else
            {
                currlen++;
            }
            
            /*  return string,
            if (currlen > maxlen)
            {
                maxlen = currlen;
                maxstart = i-currlen+1;
            }
            */
            
            maxlen = max(maxlen, currlen);
        }
        
        /* return s.substr(resstart, maxlen);  */
        return maxlen;
        
    }
