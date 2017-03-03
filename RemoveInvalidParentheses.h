/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/remove-invalid-parentheses/
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

/* 1. dfs, not write yet*/

/* 2 bfs */
/* 2017-03-03, update */
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        unordered_map<string, int> map;
        
        queue<string> q;
        q.push(s);
        map[s]++;
        
        bool found = false;
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (isvalid(t))
            {
                res.push_back(t);
                found = true;
            }
            
            if (found) continue;
            
            for (int i = 0; i < t.length(); i++)
            {
                if (t[i] != '(' && t[i] != ')') continue;
                
                string tt = t.substr(0, i) + t.substr(i+1);
                
                if (!map.count(tt))
                {
                    q.push(tt);
                    map[tt]++;
                }
            }
        }
        
        return res;
    }
    
    
    bool isvalid(string s)
    {
        int count = 0;
        for (auto p : s)
        {
            if (p == '(') count++;
            else if (p == ')' && count-- == 0) return false;
        }
        
        return count == 0;
    }
