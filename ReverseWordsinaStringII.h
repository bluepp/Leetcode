/*
2016-09-06
bluepp
May the force be with me!

https://leetcode.com/problems/reverse-words-in-a-string-ii/

Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?

Related problem: Rotate Array
*/

    void reverseWords(string &s) {
        
        _reverse(s, 0, s.length()-1);
        
        int i = 0;
        while (i < s.length())
        {
            int j = i;
            while (j < s.length() && s[j] != ' ')
            {
                j++;
            }
            
            _reverse(s, i, j-1);
            
            i = j+1;
        }
    }
    
    void _reverse(string &s, int l, int r)
    {
        while (l < r)
        {
            swap(s[l++], s[r--]);
        }
    }
