/*
	bluepp
	
	2014-06-11
	2014-12-03
	
	May the force be with ME!
	
 	Problem:    Letter Combinations of a Phone Number
  	Source:     https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
 	Notes:
 	Given a digit string, return all possible letter combinations that the number could represent.
 	A mapping of digit to letters (just like on the telephone buttons) is given below.
 	Input:Digit string "23"
 	Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 	Note:
 	Although the above answer is in lexicographical order, your answer could be in any order you want.

 	Solution: ...
 */
 
 	vector<string> letterCombinations(string digits) {
        string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string s;
        vector<string> res;
       
        _comb(digits, mapping, s, res);
        return res;
    }
    
   void _comb(const string &digits, string mapping[], string &s, vector<string> &res)
    {
        if (s.size() == digits.size())
        {
            res.push_back(s);
            return;
        }
        
        string letters = mapping[digits[s.size()] -'2'];
        for (int i = 0; i < letters.size(); ++i)
        {
            s.push_back(letters[i]);
            _comb(digits, mapping, s, res);
            s.pop_back();
        }
    }
