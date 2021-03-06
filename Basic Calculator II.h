/*
  2015-06-24
  bluepp
  May the force be with me!
  
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

https://leetcode.com/problems/basic-calculator-ii/
*/

/* 2017-02-27, update */

    int calculate(string s) {
        
        int ret = 0, d = 0;
        char sign = '+';
        stack<int> nums;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0')
            {
                d = d*10 + s[i]-'0';
            }
            
            if (s[i] < '0' && s[i] != ' ' || i == s.size()-1)
            {
                if (sign == '+') nums.push(d);
                else if (sign == '-') nums.push(-d);
                else if (sign == '*' || sign == '/')
                {
                    int t = (sign == '*') ? nums.top()*d : nums.top()/d;
                    nums.pop();
                    nums.push(t);
                }
                
                sign = s[i];
                d = 0;
            }
        }
        
        while (!nums.empty())
        {
            ret += nums.top();
            nums.pop();
        }
        
        return ret;
    }





    int calculate(string s) {
        
        int ret = 0;
        unordered_map<char, int> level;
        
        level['*'] = 1;
        level['/'] = 1;
        level['+'] = 0;
        level['-'] = 0;
        
        stack<int> stk;
        stack<char> op;
        int n = s.length();
        
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ') i++;
            else if (s[i] <= '9' && s[i] >= '0')
            {
                int t = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0')
                {
                    t = t*10 + s[i]-'0';
                    i++;
                }
                
                stk.push(t);
            }
            else
            {
                while (!op.empty() && level[op.top()] >= level[s[i]])
                {
                        int b = stk.top(); stk.pop();
                        int a = stk.top(); stk.pop();
                        
                        switch(op.top())
                        {
                            case '+':
                                stk.push(a+b);
                                break;
                            case '-':
                                stk.push(a-b);
                                break;
                            case '*':
                                stk.push(a*b);
                                break;
                            case '/':
                                stk.push(a/b);
                                break;
                        }
                        
                        op.pop();
                }
                
                op.push(s[i]);
                i++;
            }
        }
        
        while (!op.empty())
        {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            
            switch(op.top())
            {
                case '+':
                    stk.push(a+b);
                    break;
                case '-':
                    stk.push(a-b);
                    break;
                case '*':
                    stk.push(a*b);
                    break;
                case '/':
                    stk.push(a/b);
                    break;
            }
            
            op.pop();
        }
        
        return stk.top();
    }
