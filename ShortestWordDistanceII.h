/*
  2015-08-11
  bluepp
  May the force be with me!
  
This is a follow up of Shortest Word Distance. 
The only difference is now you are given the list of words and your method will be called repeatedly many times 
with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words 
word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
https://leetcode.com/problems/shortest-word-distance-ii/
*/


class WordDistance {
public:
    WordDistance(vector<string>& words) {
        
        for (int i = 0; i < words.size(); i++)
        {
            map[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        
        vector<int> t1 = map[word1], t2 = map[word2];
        
        int t = INT_MAX;
        for (int i = 0; i < t1.size(); i++)
        {
            for (int j = 0; j < t2.size(); j++)
            {
                t = min(t, abs(t1[i]-t2[j]));
            }
        }
        
        return t;
    }

private:
    unordered_map<string, vector<int> > map;
};
