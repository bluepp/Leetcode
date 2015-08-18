/*
  2015-08-11
  bluepp
  May the force be with me!
  
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
https://leetcode.com/problems/shortest-word-distance/
*/

/* O(N), smart, wawa */
/* https://leetcode.com/discuss/50234/ac-java-clean-solution */
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int n = words.size();
        int idx1 = -1, idx2 = -1, dist = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            if (words[i] == word1) idx1 = i;
            else if (words[i] == word2) idx2 = i;
            
            if (idx1 != -1 && idx2 != -1)
            {
                dist = min(dist, abs(idx1-idx2));
            }
        }
        
        return dist;
    }



/* my solution, stupid!!! */
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        int n = words.size();
        unordered_map<string, vector<int> > map;
        for (int i = 0; i < n; i++)
        {
            map[words[i]].push_back(i);
        }
        
        vector<int> v1 = map[word1];
        vector<int> v2 = map[word2];
        
        int t = INT_MAX;
        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                t = min(t, abs(v1[i]-v2[j]));
            }
        }
        
        return t;
    }
