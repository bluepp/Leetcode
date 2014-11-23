/* 
  bluepp
  
  2014-05-29
  2014-07-06
  2014-08-28
  2014-08-04
  2014-11-24
  
  May the force be with me!
  
  Problem:    Anagrams

  Source:     https://oj.leetcode.com/problems/anagrams/
  Notes:
  Given an array of strings, return all groups of strings that are anagrams.
  Note: All inputs will be in lower-case.

  Solution: Sort the string to see if they're anagrams.
           
*/

  vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        int n = strs.size();
        typedef unordered_map<string, vector<int>> MAP;
        MAP map;
        
        for (int i = 0; i < n; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(i);
        }
        
        MAP::iterator it = map.begin();
        for (; it != map.end(); it++)
        {
            vector<int> index = it->second;
            
            if (index.size() > 1)
            {
                for (int i = 0; i < index.size(); i++)
                {
                    string s = strs[index[i]];
                    res.push_back(s);
                }
            }
        }
        
        return res;
    }


---------------------

vector<string> anagrams(vector<string> & strs)
{
    typedef unordered_map(string, int) MAP;
    MAP anagram;
    vector<string> res;
    
    for(int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        MAP::iterator it = anagram.find(s);
        
        if (it == anagram.end())
        {
            anagrams[s] = i;  
        else
        {
            if (it->second >= 0)
            {
                res.push_back(strs[it->second]);
                it->second = -1;
            }
            
            res.push_back(strs[i]);
        }
        
    }
    
    return res;
  
}

