/*
	bluepp
	2014-06-07
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
