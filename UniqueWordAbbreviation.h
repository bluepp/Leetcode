/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/unique-word-abbreviation/
An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
Show Company Tags
Show Tags
Show Similar Problems

*/

class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> map;
    
    string abbr(string str)
    {
        string s;
        int n = str.length();
        if (n <= 2)
        {
            s = str;
        }
        else
        {
            s = str[0] + to_string(n-2)+ str[n-1];
        }
        
        return s;
    }
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        
        for (auto p : dictionary)
        {
            string s = abbr(p);
            map[s].push_back(p);
        }
    }

    bool isUnique(string word) {
        
        string s = abbr(word);
        
        if (!map.count(s)) return true;
        
        vector<string> strs = map[s];
        
        for (auto p : strs)
        {
            if (p != word) return false;
        }
        
        return true;
    }
};
