/*
    bluepp
    2014-06-09
    May the force be with me!
    
    Problem:    Generate Parentheses
    Source:     https://oj.leetcode.com/problems/generate-parentheses/
    Notes:
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    For example, given n = 3, a solution set is:
    "((()))", "(()())", "(())()", "()(())", "()()()"

    Solution: Place n left '(' and n right ')'.
           Cannot place ')' if there are no enough matching '('.
 */
 
 vector<string> res;
    vector<string> generateParenthesis(int n) {
        
        res.clear();
        _gen(n, n, "");
        
        return res;
    }
    
    void _gen(int left, int right, string s)
    {
       if (left == 0 && right == 0)
       {
           res.push_back(s);
           return;
       }
       if (left > 0)
       {
           _gen(left-1, right,s+"(");
       }
       if (right > left)
       {
           _gen(left,right-1, s+")");
       }
        
    }
