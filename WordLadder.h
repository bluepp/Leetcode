/*
    bluepp
    2014-07-02
    May the force be with me!
    
    
 Problem:    Word Ladder
 Source:     https://oj.leetcode.com/problems/word-ladder/
 Notes:
 Given two words (start and end), and a dictionary, find the length of shortest transformation 
 sequence from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Solution: BFS.
*/


    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        int n = start.size();
        
        while (!q.empty())
        {
            pair<string, int> orig = q.front();
            string str = orig.first; q.pop();
            
            for (int i = 0; i < n; i++)
            {
                string word = str;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    
                    if (word == end) return orig.second+1;
                    if (dict.find(word) != dict.end())
                    {
                        q.push(make_pair(word, orig.second+1));
                        dict.erase(word);
                    }
                }
                
            }
        }
        
        return 0;
        
    }
