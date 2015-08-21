/*
  2015-08-21
  bluepp
  May the force be with me!
  
  Given a string, determine if a permutation of the string could form a palindrome.

  For example,
  "code" -> False, "aab" -> True, "carerac" -> True.
  https://leetcode.com/problems/palindrome-permutation/
*/

/* another way, works */
    bool canPermutePalindrome(string s) {
        int n = s.length();
        if (n < 2) return true;
        
        unordered_map<char, int> map;
        for (int i = 0; i < n; i++)
        {
            if (!map.count(s[i]))
            {
                map[s[i]] = i;
            }
            else
            {
                map.erase(s[i]);
            }
        }
        
        return (n%2) ? map.size() == 1 : map.size() == 0;
    }






/* does not pass */
/* "AaBb//a" */ 

    bool canPermutePalindrome(string s) {
        int n = s.length();
        if (n < 2) return true;
        
        int x = s[0]-'a';
        int t = 0;
        for (int i = 1; i < n; i++)
        {
            x ^= s[i] - 'a';
        }
        
        if (n%2 != 0)
        {
            int index = 0;
            for (int i = 0; i < n; i++)
            {
                if (x == s[i]-'a') 
                {
                    index = i;
                    break;
                }
            }
            
            t= s[0]-'a';
            for (int i = 1; i < n; i++)
            {
                if (i == index) continue;
                t ^= s[i]-'a';
            }
            
            x = t;
        }
        
        return x == 0;
    }
  
