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


/* 2016-06-30, another one */

class ValidWordAbbr {
private:
    unordered_map<string, string> map;

public:
    ValidWordAbbr(vector<string> &dictionary) {
        
        for (auto p : dictionary)
        {
            string t = p[0] + to_string(p.length()-2) + p.back();
            
            if (map.find(t) != map.end() && map[t] != p)
            {
                map[t] = "";
            }
            else
            {
                map[t] = p;
            }
        }
        
    }

    bool isUnique(string word) {
        
        string t = word[0] + to_string(word.length()-2) + word.back();
        
        return map.find(t) == map.end() || map[t] == word;
      
    }
};



/* 2016-06-25, update */
class ValidWordAbbr {
private:
   unordered_map<string, set<string>> map;
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto p : dictionary)
        {
            string k = p[0] + to_string(p.length()-2) + p.back();
            map[k].insert(p);
        }
    }

    bool isUnique(string word) {
        
        string k = word[0] + to_string(word.length()-2) + word.back();
        return map[k].count(word) == map[k].size();
    }
};
