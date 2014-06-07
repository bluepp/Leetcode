/* 
    bluepp
    2014-06-08
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
        stack<int> s;
        
        for (int i = 0;i < tokens.size(); i ++)
        {
            if (tokens[i] != "+" && tokens[i] != "-"
                && tokens[i] != "*" && tokens[i] != "/")
                s.push(stoi(tokens[i]));
            else
            {
                int tmp = 0;
                int r = s.top(); s.pop();
                int l = s.top(); s.pop();
                
                if (tokens[i] == "+")
                    tmp = l + r;
                else if (tokens[i] == "-")
                    tmp = l-r;
                else if (tokens[i] == "*")
                    tmp = l*r;
                else
                    tmp = l/r;
                s.push(tmp);    
            }
                
        }
        
        return s.top();
    }
