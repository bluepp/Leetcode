/*
    bluepp
    
    2014-06-09
    2014-07-11
    2014-08-14
    2014-09-16
    2014-09-21
    2014-10-23
    2014-11-12
    
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
 
 /* 2014-09-21, my version */
     vector<string> generateParenthesis(int n) {
        vector<string> res;
        _gen(n, n, "", res);
        
        return res;
    }
    
    void _gen(int l, int r, string s, vector<string> &res)
    {
        if (l == 0 && r == 0)
        {
            res.push_back(s);
            return;
        }
        
        if (l > 0) _gen(l-1, r, s+"(", res);
        if (r > l) _gen(l, r-1, s+")", res);
    }
 
 
 
 
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        generateParenthesisRe(n, n, "");
        return res;
    }
    
    void generateParenthesisRe(int left, int right, string s) {
        if (left == 0 && right == 0)
            res.push_back(s);
        if (left > 0)
            generateParenthesisRe(left - 1, right, s + "(");
        if (right > left)
            generateParenthesisRe(left, right - 1, s + ")");
    }
