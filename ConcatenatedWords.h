/*
bluepp
2017-02-06
May the force be with me!

https://leetcode.com/problems/concatenated-words/

Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> res;
        unordered_set<string> dict(words.begin(), words.end());
        for (string word : words) {
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 0; i < n; ++i) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; ++j) {
                    if (j - i < n && dict.count(word.substr(i, j - i))) {
                        dp[j] = true;
                    }
                }
                if (dp[n]) {res.push_back(word); break;}
            }
        }
        return res;
        
    }
