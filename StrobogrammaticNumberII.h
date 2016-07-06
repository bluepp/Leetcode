/*
  2015-08-12
  bluepp
  May the force be with me!
  
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
https://leetcode.com/problems/strobogrammatic-number-ii/

*/

/* 2016-07-07, update */

    vector<string> findStrobogrammatic(int n) {
        
        return find(n, n);
    }
    
    vector<string> find(int m, int n)
    {
        if (m == 0)
        {
            return {""};
        }
        if (m == 1)
        {
            return {"0", "1", "8"};
        }
        
        vector<string> t = find(m-2, n);
        
        vector<string> res;
        
        for (auto a : t)
        {
            if (m != n)
            {
                res.push_back("0"+ a + "0");
            }
            
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        
        return res;
        
    }


/* http://likemyblogger.blogspot.com/2015/08/leetcode-247-strobogrammatic-number-ii.html */
/* recursion */
    vector<string> findStrobogrammatic(int n) {
        return find(n, n);
    }
    
    vector<string> find(int n, int nn)
    {
        vector<string> res;
        if (n == 0) return res;
        if (n == 1)
        {
            res = {"0", "1", "8"};
            return res;
        }
        if (n == 2)
        {
            if (n < nn)
            {
                res = {"00", "11", "69", "88", "96"};
            }
            else
            {
                res = {"11", "69", "88", "96"};
            }
            
            return res;
        }
        
        vector<string> tmp = find(n-2, nn);
        
        for (auto s : tmp)
        {
            if (n < nn)
            {
                string s0 = "0"+s+"0";
                res.push_back(s0);
            }
            
            string s1 = "1"+s+"1";
            res.push_back(s1);
            
            string s2 = "8"+s+"8";
            res.push_back(s2);
            
            string s3 = "6"+s+"9";
            res.push_back(s3);
            
            string s4 = "9"+s+"6";
            res.push_back(s4);
        }
        
        return res;
    }
