/*
    bluepp
    2014-06-12
    2014-07-15
    2014-08-27
    
    May the force be with me!
    Believe yoursele!!!
    
    Problem:    Longest Valid Parentheses
    Source:     https://oj.leetcode.com/problems/longest-valid-parentheses/
    Notes:
    Given a string containing just the characters '(' and ')', find the length of the longest valid 
    (well-formed) parentheses substring.
    For "(()", the longest valid parentheses substring is "()", which has length = 2.
    Another example is ")()())", where the longest valid parentheses substring is "()()", 
    which has length = 4.

    Solution: O(n).
 */
 
/* http://haixiaoyang.wordpress.com/?s=parentheses */
 
     int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> stk;
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                if(!stk.empty() && s[stk.top()] == '(')
                {
                    stk.pop();
                    res = max(res, stk.empty() ? i+1:i-stk.top());
                }
                else stk.push(i);
            }
            
        }
        
        return res;
        
    }
