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
/* 2017-02-05, update */
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        unordered_map<string, int> visited;
        queue<string> q;
        
        q.push(s);
        visited[s]++;
        bool found = false;
        
        while (!q.empty())
        {
            s = q.front();
            q.pop();
            
            if (isvalid(s))
            {
                res.push_back(s);
                found = true;
            }
            
            if (found) continue;
            
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != '(' && s[i] != ')') continue;
                
                string t = s.substr(0, i) + s.substr(i+1);
                
                if (!visited.count(t))
                {
                    q.push(t);
                    visited[t]++;
                }
            }
        }
        
        return res;
    }
    
    bool isvalid(string t)
    {
        int count = 0;
        
        for (auto p : t)
        {
            if (p == '(') count++;
            else if (p == ')' &&  count-- == 0) return false;
        }
        
        return count == 0;
    }
