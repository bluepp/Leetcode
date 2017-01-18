/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/palindrome-pairs/

Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

/* 2017-01-19, update */

    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        
        for (int i = 0; i < words.size(); ++i) 
        {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for (int i = 0; i < words.size(); ++i) 
        {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            
            if (m.count(t) && m[t] != i) 
            {
                res.push_back({i, m[t]});
            }
            
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; ++it) 
            {
                int d = *it;
                
                if (isValid(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
                    res.push_back({i, m[t.substr(len - d)]});
                }
                if (isValid(t, d, len - 1) && m.count(t.substr(0, d))) {
                    res.push_back({m[t.substr(0, d)], i});
                }
            }
        }
        
        return res;
    }
    
    bool isValid(string t, int l, int r)
    {
        while (l < r)
        {
            if (t[l++] != t[r--]) return false;
        }
        
        return true;
    }



   vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> result;
        if(words.empty()) return result;
        unordered_map<string, int> table; //words and its corresponding index;
        for(int i = 0; i < words.size(); i++) table[words[i]]=i;
        for(int i = 0; i < words.size(); i++) 
        {
            string cur = words[i];
            reverse(cur.begin(), cur.end());
            int t=0, len=cur.size();
            for(int l = 0; l <= len; l++) //l is the length of the sub-string;
            {
                if(isPal(cur,0, l-1))  //the current word will work as prefix;
                {
                    string tmp = cur.substr(l);
                    if(table.count(tmp))  //accelerate the checking process;
                    {
                        t = table[tmp];
                        if((t!=i) && (len>=words[t].size())) //avoid duplicates;
                        result.push_back(vector<int>{i, t}); //the matched word will be the suffix;
                    }
                }
                if(isPal(cur, l, len-1)) //the current word will work as suffix;
                {
                    string tmp = cur.substr(0,l); 
                    if(table.count(tmp)) 
                    {
                        t = table[tmp];
                        if((t!=i) && (len>words[t].size())) //avoid duplicates;
                        result.push_back(vector<int>{t, i}); //the matched word the prefix;
                    }
                }
            }
        }
        return result;
       
    }
    
    bool isPal(string& s, int start, int end)  //start and end refer to index;
    {
        while(s[start] == s[end]) start++, end--;
        return start >= end;
    }
    
    
    /* ------------------------- */


    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> res;
        if (!words.size()) return res;
        unordered_map<string, size_t> word_idx;
        for (size_t i = 0; i < words.size(); ++i) {
            word_idx[words[i]] = i;
        }
        vector<int> slu(2);
        for (size_t i = 0; i < words.size(); ++i) {
            size_t len = words[i].length();
            for (size_t l = 0; l <= len; ++l) {
                string left = words[i].substr(0, l);
                string right = words[i].substr(l);
                string rleft = left;
                string rright = right;
                reverse(rleft.begin(), rleft.end());
                reverse(rright.begin(), rright.end());
                if (word_idx.find(rleft) != word_idx.end()) {
                    if (word_idx[rleft] != i && isPalindrome(right)) {
                        slu[0] = i;
                        slu[1] = word_idx[rleft];
                        res.push_back(slu);                        
                    }

                }
                if (l != 0 && word_idx.find(rright) != word_idx.end()) {
                    if (word_idx[rright] != i && isPalindrome(left)) {
                        slu[0] = word_idx[rright];
                        slu[1] = i;
                        res.push_back(slu);                        
                    }

                }

            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        size_t i = 0; 
        size_t j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }

        return true;
    }
