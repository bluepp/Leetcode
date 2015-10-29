/*
  2015-10-30
  bluepp
  May the force be with me!
  
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

https://leetcode.com/problems/word-pattern/
*/

    bool wordPattern(string pattern, string str) {
        
       vector <string> a, b;
        stringstream ss(str);
        string t;
        for (auto e: pattern) {
            a.push_back(to_string(e));
        }
        while (getline(ss, t, ' ')) {
            b.push_back(t);
        }
        
        if (a.size() != b.size()) return false;
        return a.size() == b.size() && match(a, b) && match(b, a)
    }
    
     bool match(vector<string> &a, vector<string> &b) {
        unordered_map <string, string> mp;
        for (int i = 0; i < a.size(); ++i) {
            if (!mp.count(a[i])) {
                mp[a[i]] = b[i];
            } else if (mp[a[i]] != b[i]) {
                return false;
            }
        }
        return true;
    }
