/*
	bluepp
	2014-06-9
	2014-07-11
	2014-08-14
	May the force be with me!
	
 	Source:     https://oj.leetcode.com/problems/gray-code/
 	Notes:
 	The gray code is a binary numeral system where two successive values differ in only one bit.
 	Given a non-negative integer n representing the total number of bits in the code, print the 
 	sequence of gray code. A gray code sequence must begin with 0.
 	For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 		00 - 0
 		01 - 1
 		11 - 3
 		10 - 2
 	Note:
 	For a given n, a gray code sequence is not uniquely defined.
 	For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 	For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 	Solution: Refer to http://en.wikipedia.org/wiki/Gray_code.
 */
 
 	vector<int> grayCode(int n) {
        vector<int> res(1<<n, 0);
       
        for(int i = 1; i < (1<<n); i++)
        {
            res[i] = (i >> 1) ^ i;
        }
        
        return res;
    }
