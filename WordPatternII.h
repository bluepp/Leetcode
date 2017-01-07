/*
bluepp
2016-06-09
May the force be with me!

https://leetcode.com/problems/word-pattern-ii/

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.

*/

    bool wordPatternMatch(string pattern, string str) {
        
        unordered_map<char, string> map;
        return _help(pattern, 0, str, 0, map);
    }
    
    bool _help(string pattern, int p, string str, int r, unordered_map<char, string> map)
    {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        
        char c = pattern[p];
        
        for (int i = r; i < str.size(); i++)
        {
            string t = str.substr(r, i-r+1);
            
            if (map.count(c) && map[c] == t)
            {
                if (_help(pattern, p+1, str, i+1, map)) return true;
            }
            else if (!map.count(c))
            {
                bool b = false;
                
                for (auto it : map)
                {
                    if (it.second == t) b = true;
                }
                
                if (!b)
                {
                    map[c] = t;
                    if (_help(pattern, p+1, str, i+1, map)) return true;
                    map.erase(c);
                }
            }
        }
        
        return false;
    }
