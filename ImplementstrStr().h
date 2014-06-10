/* 
    bluepp
    2014-06-10
    May the force be with me!
    
    Problem:    Implement strStr()
    Source:     https://oj.leetcode.com/problems/implement-strstr/
    Notes:
    Implement strStr().
    Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

    Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */
 
 char *strStr(char *haystack, char *needle)
    {
        while (true)
        {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *n == *h)
            {
                n++;
                h++;
            }    
            
            if (*n == '\0')
                return haystack;
            if (*h == '\0')
                return NULL;
            haystack++;    
        }
        
    }
