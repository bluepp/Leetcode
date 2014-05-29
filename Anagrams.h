/* 
  bluepp
  2014-05-29
  May the force be with me!
  
  Problem:    Anagrams

  Source:     http://leetcode.com/onlinejudge#question_49
  Notes:
  Given an array of strings, return all groups of strings that are anagrams.
  Note: All inputs will be in lower-case.

  Solution: Sort the string to see if they're anagrams.
           
*/

vector<string> anagrams(vector<string>& strs)
{
    typedef map<string, vector<int>> MAP;
    MAP map;
    
    for (int i = 0; i < strs.ize(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        map[s].push_back(i);
    }
    
    vector<string> res;
    MAP::iterator it = map.begin();
    
    for(;it != map.end(); it++)
    {
        vector<int> anagram = it->second();
        if(anagram.size() > 1)
        {
            for(int i = 0; i < anagram.size(); i++)
                res.push_back(strs[anagrams[i]);
        }
    }
    
    return res;
    
}
