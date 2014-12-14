/*
  bluepp
  2014-12-14
  May the force be with me!
  
https://oj.leetcode.com/problems/word-ladder-ii/  
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string> > traces;
        vector<unordered_set<string> > level(2);
        int curr = 0, prev = 1;
        level[curr].insert(start);
        dict.insert(end);
        
        while (true)
        {
            prev = !prev;
            curr = !curr;
            level[curr].clear();
            
            for(unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); it++)
            {
                dict.erase(*it);
            }
            
            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); it++)
            {
                string word = *it;
                
                for (int i = 0; i < word.size(); i++)
                {
                    char before = word[i];
                    
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == before) continue;
                        
                        word[i] = c;
                        if (dict.find(word) != dict.end())
                        {
                            traces[word].push_back(*it);
                            level[curr].insert(word);
                        }
                    }
                    
                    word[i] = before;
                }
            }
            
            if (level[curr].empty() || level[curr].count(end) > 0) break;
        }
        
        vector<vector<string> > res;
        vector<string> onepath;
        if (!traces.empty())
        {
            buildresult(traces, res, onepath, end);
        }
        
        return res;
    }
    
    
    void buildresult(map<string, vector<string> > &traces, vector<vector<string> > &res, vector<string> &onepath, string word)
    {
        if (traces.count(word) == 0)
        {
            vector<string> copy(onepath);
            copy.push_back(word);
            reverse(copy.begin(), copy.end());
            res.push_back(copy);
            return;
        }
        
        vector<string> &s = traces[word];
        onepath.push_back(word);
        for (vector<string>::iterator it = s.begin(); it != s.end(); it++)
        {
            buildresult(traces, res, onepath, *it);
        }
        onepath.pop_back();
    }
