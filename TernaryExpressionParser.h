/*
bluepp
2016-12-09
May the force be with me!

https://leetcode.com/problems/ternary-expression-parser/

Given a string representing arbitrarily nested ternary expressions, calculate the result of the expression. You can always assume that the given expression is valid and only consists of digits 0-9, ?, :, T and F (T and F represent True and False respectively).

Note:

The length of the given string is ≤ 10000.
Each number will contain only one digit.
The conditional expressions group right-to-left (as usual in most languages).
The condition will always be either T or F. That is, the condition will never be a digit.
The result of the expression will always evaluate to either a digit 0-9, T or F.
Example 1:

Input: "T?2:3"

Output: "2"

Explanation: If true, then result is 2; otherwise result is 3.
Example 2:

Input: "F?1:T?4:5"

Output: "4"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(F ? 1 : (T ? 4 : 5))"                   "(F ? 1 : (T ? 4 : 5))"
          -> "(F ? 1 : 4)"                 or       -> "(T ? 4 : 5)"
          -> "4"                                    -> "4"
Example 3:

Input: "T?T?F:5:3"

Output: "F"

Explanation: The conditional expressions group right-to-left. Using parenthesis, it is read/evaluated as:

             "(T ? (T ? F : 5) : 3)"                   "(T ? (T ? F : 5) : 3)"
          -> "(T ? F : 3)"                 or       -> "(T ? F : 5)"
          -> "F"                                    -> "F"
*/

/* 2017-02-20, update */
    string parseTernary(string expression) {
        
        string res;
        stack<char> stk;
        
        int n = expression.size();
        for (int i = n-1; i >= 0; i--)
        {
            char ch = expression[i];
            
            if (!stk.empty() && stk.top() == '?')
            {
                stk.pop();
                char c1 = stk.top();
                stk.pop();
                stk.pop();
                char c2 = stk.top();
                stk.pop();
                
                if (ch == 'T') stk.push(c1);
                else if (ch == 'F') stk.push(c2);
            }
            else
            {
                stk.push(ch);
            }
        }
        
        return res+stk.top();
    }



/* 2017-01-17, my versiion */
   string parseTernary(string expression) {
        
        string res = "";
        int n = expression.length();
        stack<char> stk;
        
        for (int i = n-1; i >= 0; i--)
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                stk.push(expression[i]);
            }
            else if (expression[i] == 'T' || expression[i] == 'F')
            {
                if (i+1 < n && expression[i+1] == '?')
                {
                    char t1 = stk.top(); stk.pop();
                    char t2 = stk.top(); stk.pop();
                    
                    if (expression[i] == 'T') stk.push(t1);
                    else stk.push(t2);
                }
                else stk.push(expression[i]);
            }
            
        }
        
        return stk.empty() ? "" : res + stk.top();
    }
