/*
    bluepp
    2014-06-12
    2014-07-15
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
        int ret = 0;
        stack<int> stk;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')')
            {
                if (!stk.empty() && s[stk.top()] == '(') 
                {
                    stk.pop();
                    ret = max(ret, stk.empty()?i+1:i-stk.top());
                }
                else
                {
                    stk.push(i);
                }
            }
            
        }
        
        return ret;
        
    }
