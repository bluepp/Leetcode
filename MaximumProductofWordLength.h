/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/maximum-product-of-word-lengths/

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

*/

/* mask, to record ,character */
   int maxProduct(vector<string>& words) {
        
        int ret = 0;
        int n = words.size();
        vector<int> vec(n, 0);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                vec[i] |= 1 << (words[i][j] - 'a');
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (vec[i] & vec[j]) continue;
                
                int t1 = words[i].length(), t2 = words[j].length();
                ret = max(ret, t1*t2);
            }
        }
        
        return ret;
        
    }



/* hash table to recored lenth */
   int maxProduct(vector<string>& words) {
        
        int ret = 0;
        unordered_map<int, int> map;
        
        for (auto str : words)
        {
            int mask = 0;
            for (p : str)
            {
                mask |= 1 << (p - 'a');
            }
            
            map[mask] = max(map[mask], (int)str.size());
            
            for (auto it : map)
            {
                if (!(mask & it.first))
                {
                    ret = max(ret, (int)str.size() * it.second);
                }
            }
        }
        
        return ret;
      
    }
