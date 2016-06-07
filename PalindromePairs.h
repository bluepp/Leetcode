/*
bluepp
2016-06-08
May the force be with me!

https://leetcode.com/problems/palindrome-pairs/

Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/

    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> res;
        if (!words.size()) return res;
        unordered_map<string, size_t> word_idx;
        for (size_t i = 0; i < words.size(); ++i) {
            word_idx[words[i]] = i;
        }
        vector<int> slu(2);
        for (size_t i = 0; i < words.size(); ++i) {
            size_t len = words[i].length();
            for (size_t l = 0; l <= len; ++l) {
                string left = words[i].substr(0, l);
                string right = words[i].substr(l);
                string rleft = left;
                string rright = right;
                reverse(rleft.begin(), rleft.end());
                reverse(rright.begin(), rright.end());
                if (word_idx.find(rleft) != word_idx.end()) {
                    if (word_idx[rleft] != i && isPalindrome(right)) {
                        slu[0] = i;
                        slu[1] = word_idx[rleft];
                        res.push_back(slu);                        
                    }

                }
                if (l != 0 && word_idx.find(rright) != word_idx.end()) {
                    if (word_idx[rright] != i && isPalindrome(left)) {
                        slu[0] = word_idx[rright];
                        slu[1] = i;
                        res.push_back(slu);                        
                    }

                }

            }
        }
        return res;
    }
    
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        size_t i = 0; 
        size_t j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }

        return true;
    }
