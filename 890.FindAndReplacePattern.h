/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for (auto word : words) {
            
            unordered_map<char, char> m1, m2;
            
            if (word.size() != pattern.size()) {
                continue;
            }
            
            int i = 0;
            for (; i < word.size(); i++) {
                if (!m1.count(word[i])) {
                    m1[word[i]] = pattern[i];
                } else if (m1[word[i]] != pattern[i]){
                    break;
                }
                
                if (!m2.count(pattern[i])){
                    m2[pattern[i]] = word[i];
                } else if (m2[pattern[i]] != word[i]){
                    break;
                }
            }
            
            if (i == word.size()){
                res.push_back(word);
            }
            
        }
        
        return res;
        
    }


/* ----------------------------------------------------- */






vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for (auto word : words) {
            if (_ispattern(word, pattern)) {
                res.push_back(word);
            }
        }
        
        return res;
       
    }
    
    
    bool _ispattern(string p1, string p2) {
        unordered_map<char,char> m1, m2;
        
        for (int i = 0; i < p1.size(); i++) {
            if (m1.count(p1[i]) && m1[p1[i]] != p2[i]) {
                return false;
            } else if (m2.count(p2[i]) && m2[p2[i]] != p1[i]) {
                return false;
            } else {
                m1[p1[i]] = p2[i];
                m2[p2[i]] = p1[i];
            }
        }
        
        return true;
    }
