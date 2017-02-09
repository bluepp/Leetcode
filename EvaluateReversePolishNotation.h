/* 
    bluepp
    2014-06-08
    2014-07-10
    2014-08-13
    2014-08-28
    
    May the force be with me!
    
    Problem:    Evaluate Reverse Polish Notation
    Source:     https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
    Valid operators are +, -, *, /. Each operand may be an integer or another expression.
    Some examples:
        ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
        ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
        Solution: stack.
 */
 
     int evalRPN(vector<string>& tokens) {
      
        stack<int> stk;
        
        for (auto str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int t1 = stk.top(); 
                stk.pop();
                int t2 = stk.top();
                stk.pop();
                
                if (str == "+") stk.push(t1+t2);
                else if (str == "*") stk.push(t1*t2);
                else if (str == "-") stk.push(t2-t1);
                else if (str == "/") stk.push(t2/t1);
            }
            else
            {
                stk.push(stoi(str));
            }
        }
        
        return stk.empty() ? 0 : stk.top();
    }
