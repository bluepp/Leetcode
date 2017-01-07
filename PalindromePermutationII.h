/*
  2015-08-23
  bluepp
  May the force be with me!
  
Given a string s, return all the palindromic permutations (without duplicates) of it.
Return an empty list if no palindromic permutation could be form.

For example:
Given s = "aabb", return ["abba", "baab"].
Given s = "abc", return [].
https://leetcode.com/problems/palindrome-permutation-ii/
*/

/* 2017-01-08, update */
    vector<string> generatePalindromes(string s) {

        vector<string> res;
        unordered_map<char, int> map;
        
        
        for (auto p : s) map[p]++;
        
        string t = "", mid = "";
        for (auto it : map) {
            
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            
            if (mid.size() > 1) return {};
        }
        
        _perm(t, 0, mid, res);
        
        return res;
    }
    
    
    void _perm(string t, int start, string mid, vector<string> &res)
    {
        if (start >= t.size()) 
        {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        }
        
        for (int i = start; i < t.size(); i++)
        {
            if (i != start && t[i] == t[start]) continue;
            
            swap(t[i], t[start]);
            _perm(t, start+1, mid, res);
            swap(t[i], t[start]);
        }
    }







/× https://leetcode.com/discuss/53626/ac-java-solution-with-explanation ×/
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> map;
        
        int odd = 0;
        for (auto p : s)
        {
            map[p]++;
            if (map[p] % 2) odd ++;
            else odd--;
        }
        
        if (odd > 1) return res;
        
        string list = "";
        string mid = "";
        for (auto p : map)
        {
            if (p.second % 2) mid += p.first;
        
            for (int i = 0; i < p.second/2; i++)
            {
                list += p.first;
            }
        }
        
        string str = "";
        vector<bool> used(list.size(), false);
        _perm(list, mid, str, used, res);
        return res;
    }
    
    void _perm(string list, string mid, string str, vector<bool> used, vector<string> &res)
    {
        if (str.length() == list.size())
        {
            string t = str;
            reverse(t.begin(), t.end());
            res.push_back(str+mid+t);
            return;
        }
        
        for (int i = 0; i < list.size(); i++)
        {
            if (i > 0 && list[i] == list[i-1] && !used[i-1]) continue;
            
            if (!used[i])
            {
                used[i] = true;
                str.push_back(list[i]);
                _perm(list, mid, str, used, res);
                str.pop_back();
                used[i] = false;
            }
        }
    }





/* TLS */
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        
        string str = "";
        _pal(s, 0, str, res);
        return res;
    }
    
    void _pal(string s, int start, string str, vector<string> &res)
    {
        if (s.size() == str.size() && is_pal(str))
        {
            res.push_back(str);
            return;
        }
        
        for (int i = start; i < s.length(); i++)
        {
            str += s[i];
            _pal(s, i+1, str, res);
    //        str.erase(str.end());
        }
    }
    
    bool is_pal(string s)
    {
        int n = s.length();
        if (n < 2) return true;
        int l = 0, r = n-1;
        while (l < r)
        {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        
        return true;
    }
