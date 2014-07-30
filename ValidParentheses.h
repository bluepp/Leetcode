/*
    bluepp
    2014-07-01
    2014-07-30
    May the force be with me!
    
 Problem:    Valid Parentheses
 Source:     https://oj.leetcode.com/problems/valid-parentheses/
 Notes:
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 Solution: stack.
 */


    bool isValid(string s) {
        
        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ')' && !stk.empty())
            {
                if (stk.top() == '(') stk.pop();
                else return false;
            }
            else if (s[i] == ']' && !stk.empty())
            {
                if (stk.top() == '[') stk.pop();
                else return false;
            }
            else if (s[i] == '}' && !stk.empty())
            {
                if (stk.top() == '{') stk.pop();
                else return false;
            }
            else
                return false;
            
        }
        
        return stk.empty();
   }
    
