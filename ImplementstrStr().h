/* 
    bluepp
    2014-06-10
    2014-07-11
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
            char *p1 = haystack, *p2 = needle;
            while (*p1 != '\0' && *p1 == *p2)
            {
                p1++; p2++;
            }
            
            if (*p2 == '\0') return haystack;
            if (*p1 == '\0') return NULL;
            haystack++;
        }
       
    }
