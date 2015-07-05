/*
  2015-06-14
  bluepp
  May the force be with me!
  
  Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

https://leetcode.com/problems/basic-calculator/
*/

/* update, 2015-07-05 */
    int calculate(string s) {
        
        int n = s.length();
        
        stack<int> stk;
        stack<char> op;
        stack<char> par;
        
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ') i++;
            else if (s[i] == '(')
            {
                if (!op.empty() && op.top() == '-')
                {
                    par.push('-');
                }
                else
                {
                    par.push('+');
                }
                
                i++;
            }
            else if (s[i] == ')')
            {
                par.pop();
                i++;
            }
            else if (s[i] <= '9' && s[i] >= '0')
            {
                int t = 0;
                
                while (i < n && s[i] <= '9' && s[i] >= '0')
                {
                    t = t * 10 + s[i]-'0';
                    i++;
                }
                
                if (op.empty()) stk.push(t);
                else
                {
                    int tnum = stk.top(); stk.pop();
                    if (op.top() == '+')
                    {
                        stk.push(tnum+t);
                    }
                    else
                    {
                        stk.push(tnum-t);
                    }
                    
                    op.pop();
                }
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (par.empty()) op.push(s[i]);
                else
                {
                    if (par.top() == '+' && s[i] == '+' || par.top() == '-' && s[i] == '-')
                    {
                        op.push('+');
                    }
                    else
                    {
                        op.push('-');
                    }
                }
                
                i++;
            }
        
        }
        
        return stk.top();
    }
