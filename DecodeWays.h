/*
    bluepp  
    2014-06-07
    2014-07-10
    May the force be with me!
    
    Problem:    Decode Ways
    Source:     https://oj.leetcode.com/problems/decode-ways/
    Notes:
    A message containing letters from A-Z is being encoded to numbers using the following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number of ways to decode it.
    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
    The number of ways decoding "12" is 2.

    Solution: dp. Note that '0' must be decoded in together with the number in front of it.
*/

    int numDecodings(string s) {
 
        int len = s.size();
	    if (len == 0) return 0;

	    int ways[len+1];
	    //this value is set for easy calculation for last two numbers
	    ways[len] = 1; 
	    //the ways decoding for last number
	    ways[len-1] = s[len-1] == '0'? 0 : 1; 

	    for (int i = len-2; i >= 0; --i)
	    {
		    char c0 = s[i];
		    if(c0 == '0')
		    {
			    ways[i] = 0;
			    continue;
		    }

		    //decode current number only
		    ways[i] = ways[i+1];

		    //decode with next number to be two
		    char c1 = s[i+1];
		    //valid two numbers decoding
		    if (c0 == '1' 
			    || (c0 == '0' && c1 != '0') 
			    || (c0 == '2' && c1 <= '6'))
			ways[i] += ways[i+2];

	    }
	    return ways[0];
    }
