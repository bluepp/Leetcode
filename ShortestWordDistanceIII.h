/*
  2015-08-11
  bluepp
  May the force be with me!
  
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
https://leetcode.com/problems/shortest-word-distance-iii/
*/

/* no hash map, ? https://leetcode.com/discuss/50715/12-16-lines-java-c */
/* update, 2015-08-18 */
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        long long dist = INT_MAX, i1 = -1, i2 = -1;
        
        for (int i=0; i<words.size(); i++)
        {
            if (words[i] == word1)
                i1 = i;
            if (words[i] == word2) {
                if (word1 == word2)
                    i1 = i2;
                i2 = i;
            }
            if (i1 != -1 && i2 != -1) dist = min(dist, abs(i1 - i2));
        }
        
        return dist;
    }


    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        unordered_map<string, vector<int> > map;
        for (int i = 0; i < words.size(); i++)
        {
            map[words[i]].push_back(i);
        }
        
        vector<int> t1 = map[word1], t2 = map[word2];
        int t = INT_MAX;
        if (t1 == t2)
        {
            for (int i = 1; i < t1.size(); i++)
            {
                t = min(t, t1[i]-t1[i-1]);
            }
        }
        else
        {
            for (int i = 0, j = 0; i < t1.size() && j < t2.size();)
            {
                t = min(t, abs(t1[i]-t2[j]));
                
                if (t1[i] < t2[j]) i++;
                else j++;
            }
        }
        
        return t;
    }
