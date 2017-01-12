/*
bluepp
2016-06-03
May the force be with me!

https://leetcode.com/problems/generalized-abbreviation/
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

/* 2017-01-12, iterative, update */
   vector<string> generateAbbreviations(string word) {
        
        vector<string> res;
        int n = word.length();
        
        for (int i = 0; i < pow(2, n); i++)
        {
            string str;
            int count = 0;
            
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    count++;
                }
                else
                {
                    if (count)
                    {
                        str += to_string(count);
                        count = 0;
                    }
                    
                    str += word[j];
                }
            }
            
            if (count > 0)
            {
                str += to_string(count);
            }
            
            res.push_back(str);
            
        }
        
        return res;
       
    }



/* straight forward recursion soluation */

    vector<string> generateAbbreviations(string word) {
       
        vector<string> result;
        result.push_back(word);
        generateAbbreviations(result, word, 0);
        
        return result;
    }
    
    void generateAbbreviations(vector<string>& result, string word, int pos) {
        for (int i = pos; i<word.length(); i++) {
            for (int j = 1; i + j<=word.length(); j++) {
                string t = word.substr(0, i);
                t += to_string(j) + word.substr(i + j);
                result.push_back(t);
                generateAbbreviations(result, t, i + 1 + to_string(j).length());
            }
        }
    }
    
/*
https://leetcode.com/discuss/93226/my-99%25-dp-solution-in-c

The idea is using dp to reduce redundant calculation. 
The subproblem is defined as abbreviations of word.substr(i). 
And for each subproblem, we have two choices, one is to keep word[i], 
the other is to replace first j characters with number and concatenate word.substr(i, j + 1) with results in dp[i + j + 1].
*/
    
   vector<string> generateAbbreviations(string word) {
        
       int N = word.size();
        vector<vector<string>> dp(N + 2);
        dp[N].emplace_back();
        dp[N + 1].emplace_back();
        for (int i = N - 1; i >= 0; --i) {
            for (auto& s : dp[i + 1]) {
                dp[i].push_back(word[i] + s);
            }
            for (int j = 1; i + j <= N; ++j) {
                string sub = word.substr(i, min(j + 1, (int)word.size() - i));
                sub.replace(0, j, to_string(j));
                for (auto& s : dp[i + j + 1]) {
                    dp[i].push_back(sub + s);
                }
            }
        }
        return dp[0];
       
    }    
    
