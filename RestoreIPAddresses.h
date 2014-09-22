/*
    bluepp
    
    2014-06-21
    2014-07-23
    2014-09-06
    2014-09-20
    2014-09-23
    
    May the force be with me!
   
 Problem:    Restore IP Addresses
 Source:     https://oj.leetcode.com/problems/restore-ip-addresses/
 Notes:
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 For example:
 Given "25525511135",
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

 Solution: DFS.
 */

/* 2014-09-23 */
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        _addr(s, res, "", 0, 0);
        return res;
    }
    
    void _addr(string s, vector<string> &res, string str, int start, int len)
    {
        if (start == s.size() && len == 4)
        {
            res.push_back(str);
            return;
        }
        
        if (len == 4) return;
        
        int length = str.size();
        if (length > 0) str.push_back('.');
        
        int num = 0;
        for (int i = start; i < s.size(); i++)
        {
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            
            str.push_back(s[i]);
            
            _addr(s, res, str, i+1, len+1);
            
            if (num == 0) break;
        }
        
        //str.resize(length); ---------------------//2014-09-23
    }




    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string vec;
        _ipaddr(s, vec, res, 0, 0);
        return res;
    }
    
    void _ipaddr(string s, string &vec, vector<string>& res, int deep, int start)
    {
        if (deep == 4 && start == s.size())
        {
            res.push_back(vec);
            return;
        }
        if (deep == 4)
            return;
        
        int num = 0, size = vec.size();
        if (size != 0)
            vec.push_back('.');
        for (int i = start; i < s.size(); i++)
        {
            num = num * 10 + s[i] - '0';
            if (num > 255)
                break;
            vec.push_back(s[i]);
            _ipaddr(s, vec, res, deep+1, i+1);
            if (num ==0)
                break;
            
        }
        
        vec.resize(size);
        
    }
