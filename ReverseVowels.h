/*
  2016-06-01
  bluepp
  May the force be with me!
  
  Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
https://leetcode.com/problems/reverse-vowels-of-a-string/
*/

    string reverseVowels(string s) {
        int n = s.length();
        int l = 0, r = n-1;
        
        while (l < r)
        {
            while (l < r && !isvowel(s[l]))
            {
                l ++;
            }
            while (l < r && !isvowel(s[r]))
            {
                r--;
            }
            
            if (l < r)
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        
        return s;
        
    }
    
    bool isvowel(char c)
    {
       return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
