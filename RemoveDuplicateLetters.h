/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/remove-duplicate-letters/

Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/

/* 2017-01-09, update */
    string removeDuplicateLetters(string s) {
        
        unordered_map<char, int> map;
        unordered_map<char, bool> visited;
        string res = "";
        
        for (auto p : s) map[p]++;
        
        for (auto p : s)
        {
            map[p]--;
            if (visited[p]) continue;
            
            while (p < res.back() && map[res.back()] > 0)
            {
                visited[res.back()] = false;
                res.pop_back();
            }
            
            res += p;
            visited[p] = true;
        }
        
        return res;
      
    }




    string removeDuplicateLetters(string s) {
        int counts[26] = {};
        bool inresult[26] = {};
        
        for(char c: s) counts[c-'a']++;
        
        string result = "";
        
        for(char c: s) {
        
            counts[c-'a']--;
            if(inresult[c-'a']) continue;
        
            while(!result.empty() && counts[result.back()-'a'] > 0 && result.back() > c){
                inresult[result.back()-'a'] = false;
                result.pop_back();
            }
        
            inresult[c-'a'] =true;
            result.push_back(c);
        }
        
        return result;
    }
