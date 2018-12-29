/* 
    bluepp
    2014-06-10
    2014-07-11
    2014-08-14
    May the force be with me!
    
    Problem:    Implement strStr()
    Source:     https://oj.leetcode.com/problems/implement-strstr/
    Notes:
    Implement strStr().
    Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

    Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */
 
 /* 2016-09-21, update */
 
     int strStr(string haystack, string needle) {
        
        int m = haystack.size(), n = needle.size();
        if (n == 0)
        {
            return 0;
        }
        if (m < n)
        {
            return -1;
        }
        
        for (int i = 0; i < m-n+1; i++)
        {
            int j = 0;
            
            while(j < n && haystack[i+j] == needle[j])
            {
                j++;
            }
            
            if (j == n)
            {
                return i;
            }
        }
        
        return -1;
     
    }
 
 
 
    char *strStr(char *haystack, char *needle) {
        
        while (true)
        {
            char *p1 = haystack, *p2 = needle;
            
            while (*p1 != '\0' && *p1 == *p2)
            {
                p1 ++;
                p2++;
            }
            
            if (*p2 == '\0') return haystack;
            if (*p1 == '\0') return NULL;
            
            haystack ++;
        }
        
    }
