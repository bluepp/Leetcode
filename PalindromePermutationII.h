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

/× https://leetcode.com/discuss/53626/ac-java-solution-with-explanation ×/
    vector<string> generatePalindromes(string s) {
        
        vector<string> res;
        unordered_map<char, int> map;
        int n = s.length();
        
        int odd = 0;
        for (auto p : s)
        {
            map[p]++;
            odd += (map[p]%2) == 1 ? 1 : -1;
        }
        
        if (odd > 1) return res;
        
        string mid = "";
        string list = "";
        for (auto p : map)
        {
            if (p.second % 2) mid += p.first;
            
            for (int i = 0; i < p.second/2; i++)
            {
                list += p.first;
            }
        }
        
        vector<bool> used(list.size(), false);
        string sb = "";
        _perm(list, mid, used, sb, res);
        
        return res;
    }
    
    void _perm(string list, string mid, vector<bool> used, string sb, vector<string> &res)
    {
        
        if (sb.length() == list.size())
        {
            string t = sb;
            reverse(t.begin(), t.end());
            
            res.push_back(sb+mid+t);
            return;
        }
        
        
        for(int i = 0; i < list.size(); i++)
        {
            if (i > 0 && list[i] == list[i-1] && !used[i-1]) continue;
            
            if (!used[i])
            {
                
                used[i] = true;
                sb += list[i];
                
                _perm(list, mid, used, sb, res);
                
                used[i] = false;
                sb.pop_back();
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
