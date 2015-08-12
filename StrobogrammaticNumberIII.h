/*
  2015-08-12
  bluepp
  May the force be with me!
  
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
https://leetcode.com/problems/strobogrammatic-number-iii/
*/

/* MLE, http://likemyblogger.blogspot.com/2015/08/leetcode-248-strobogrammatic-number-iii.html */
    int strobogrammaticInRange(string low, string high) {
        int n = high.size();
        
        vector<string> res;
        find(n, n, res);
        int count = 0;
        for (auto s : res)
        {
            if (s.size() > 1 && s[0] == '0') continue;
            if (cmp(s, low) >= 0 && cmp(s, high) <= 0)
            {
                count ++;
            }
        }
        
        return count;
    }
    
    void find(int n, int nn, vector<string> &res)
    {
        if (n == 0) return;
        else if (n == 1)
        {
            res.push_back("0");
            res.push_back("1");
            res.push_back("8");
        }
        else if (n == 2)
        {
            find(1, nn, res);
            res.push_back("11");
            res.push_back("69");
            res.push_back("88");
            res.push_back("96");
            if (n < nn) res.push_back("00");
        }
        else
        {
            find(n-1, nn, res);
            vector<string> tmp = res;
            
            for (auto s : tmp)
            {
                if (s.size() != n-2) continue;
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
        }
    }
    
    int cmp(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        
        if (n1 < n2)
        {
            for (int i = 0; i < n2-n1; i++)
            {
                s1 = "0"+s1;
            }
        }
        else if (n1 > n2)
        {
            for (int i = 0; i < n1-n2; i++)
            {
                s2 = "0"+s2;
            }
        }
        
        return s1.compare(s2);
    }
