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

/* 2 */
    vector<string> removeInvalidParentheses(string s) {
       vector<string> result;
        if(s==""){
            result.push_back(s);
            return result;
        } 
        
        /*** use the visited to record the visited string ***/
        unordered_set<string> visited;
        /*** use the deque to do the BFS ***/
        deque<string> queue;
        queue.push_back(s);
        visited.insert(s);
        bool found=false;
        
        while(!queue.empty()){
            string temp=queue.front();
            queue.pop_front();
            if(check(temp)){
                result.push_back(temp);
                found=true;
            }
        
            /*** if found, stop to increase the level depth ***/
            if(found)  continue;
            for(int i=0; i<temp.size(); i++){
                if(temp[i]!='(' && temp[i]!=')') continue;
                string str=temp.substr(0, i)+temp.substr(i+1);
                if(visited.find(str)==visited.end()){
                    queue.push_back(str);
                    visited.insert(str);
                }
            }
        }
        
        return result;
    }
    
    bool check(string s)
    {
        int count = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(') count ++;
            if (c == ')')
            {
                if (count == 0) return false;
                count --;
            }
        }
        
        return count == 0;
    }
