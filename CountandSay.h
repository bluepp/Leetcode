/*
	bluepp
	2014-06-07
	2014-07-10
	May the force be with me!
	
	Problem:    Count and Say
 	Source:     https://oj.leetcode.com/problems/count-and-say/
 	Notes:
 	The count-and-say sequence is the sequence of integers beginning as follows:
 	1, 11, 21, 1211, 111221, ...

 	1 is read off as "one 1" or 11.
 	11 is read off as "two 1s" or 21.
 	21 is read off as "one 2, then one 1" or 1211.
 	Given an integer n, generate the nth sequence.
 	Note: The sequence of integers will be represented as a string.

 	Solution: ...
*/	

/* 2016-07-17, update */

    string countAndSay(int n) {
        
        if (n <= 0)
        {
            return "";
        }
        
        string res = "1";
        int count = 0;
        
        for (int i = 1; i < n; i++)
        {
            string tmp = "";
            res.push_back('$');
            int len = res.length();
            int count = 0;
            
            for (int j = 0; j < len; j++)
            {
                if (j == 0)
                {
                    count ++;
                }
                else
                {
                    if (res[j] != res[j-1])
                    {
                        tmp += to_string(count);
                        tmp += res[j-1];
                        count = 1;
                    }
                    else
                    {
                        count ++;
                    }
                }
            }
            
            res = tmp;
        }
        
        return res;
       
    }
	
    string countAndSay(int n) {
        string res = "1";
        
        for (int i = 2; i <= n; i++)
        {
            stringstream ss;
            int j = 0, N = res.size();
            
            while (j < N)
            {
                int k = j+1;
                while (k < N && res[j] == res[k])
                {
                    k++;
                }
                ss << (k-j) << res[j];
                j = k;
            }
            
            ss >> res;
        }
        
        return res;
        
    }
