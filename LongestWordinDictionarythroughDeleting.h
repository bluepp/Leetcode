/* 
bluepp
2017-03-10
May the force be with me!

https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/?tab=Description

Given a string and a string dictionary, 
find the longest string in the dictionary that can be formed by deleting some characters of the given string. 
If there are more than one possible results, return the longest word with the smallest lexicographical order. 
If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
*/

/* 2. no sort */
    string findLongestWord(string s, vector<string>& d) {
        
        string res = "";
        
        for (string str : d)
        {
            int i = 0;
            for (char c : s)
            {
                if (i < str.size() && c == str[i]) ++i;
            }
            
            if (i == str.size() && str.size() >= res.size())
            {
                if (str.size() > res.size() || str < res)
                {
                    res = str;
                }
            }
        }
        
        return res;
    }
    
    



/* 1. sort */
    string findLongestWord(string s, vector<string>& d) {
        
        sort(d.begin(), d.end(), [](string a, string b){
            
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        
        for (string str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size()) return str;
        }
        return "";
    }
    
    
    
