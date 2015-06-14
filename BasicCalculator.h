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

    int calculate(string s) {
        
        stack<int> stk;
        stack<char> op;
        stack<bool> parneg;
        
        bool bnegop = false;
        
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (s[i] == '(')
            {
                i++;
                
                if (!op.empty() && op.top() == '-')
                {
                   parneg.push(true);
                }
                else
                {
                    parneg.push(false);
                }
            }
            else if (s[i] == ')')
            {
                i++;
                parneg.pop();
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (parneg.empty() && s[i] == '+')
                {
                    op.push('+');
                }
                else if (parneg.empty() && s[i] == '-')
                {
                    op.push('-');
                }
                else if ((!parneg.top() && s[i] == '+') || (parneg.top() && s[i] == '-')) op.push('+');
                else if ((!parneg.top() && s[i] == '-') || (parneg.top() && s[i] == '+')) op.push('-');
                
                i++;
            }
            else if (s[i] <= '9' || s[i] >= '0')
            {
                int num = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0')
                {
                    num = num * 10 + s[i]-'0';
                    i++;
                }
                
                if (!op.empty())
                {
                    int t = stk.top();
                    stk.pop();
                    
                    if (op.top() == '+')
                    {
                        stk.push(t+num);
                    }
                    else
                    {
                        stk.push(t-num);
                    }
                    
                    op.pop();
                }
                else
                {
                    stk.push(num);
                }
            }
        }
        
        return stk.empty() ? 0 : stk.top();
    }
