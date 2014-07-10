/* 
    bluepp
    2014-06-08
    2014-07-10
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
 
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        stack<int> s;
        
        for (int i = 0; i < n; i++)
        {
            string op = tokens[i];
            if (op != "+" && op != "-" && op != "*" && op != "/")
                s.push(stoi(tokens[i]));
            else
            {
                int n1 = s.top(); s.pop();
                int n2 = s.top(); s.pop();
                int n;
                
                if (op == "+") n = n1+n2;
                else if (op == "-") n = n2-n1;
                else if (op == "*") n = n1*n2;
                else n = n2/n1;
                s.push(n);
            }
        }
        
        return s.top();
    }
