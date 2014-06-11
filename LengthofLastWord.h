/*
	bluepp
	2014-06-11
	May the force be with me!
	
 	Problem:    Length of Last Word
 	Source:     https://oj.leetcode.com/problems/length-of-last-word/
 	Notes:
 	Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 	If the last word does not exist, return 0.
 	Note: A word is defined as a character sequence consists of non-space characters only.
 	For example, 
 	Given s = "Hello World",
 	return 5.

 	Solution: ...
 */
 
 	int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int res = 0;
        int i = n-1;
        for (; i >= 0; i--)
        {
            if (s[i] != ' ')
                res ++;
            else
            {
                if (res > 0)
                    break;
            }
        }
     
        return res;
    }
