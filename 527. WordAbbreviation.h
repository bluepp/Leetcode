/*
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Note:
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.
*/

    vector<string> wordsAbbreviation(vector<string>& dict) {
        
        int n = dict.size();
        vector<string> res(n);
        vector<int> pre(n, 1);
        
        for (int i = 0; i < n; ++i) {
            res[i] = abbreviate(dict[i], pre[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            while (true) {
                set<int> s;
                for (int j = i + 1; j < n; ++j) {
                    if (res[j] == res[i]) s.insert(j);
                }
                if (s.empty()) break;
                s.insert(i);
                for (auto a : s) {
                    res[a] = abbreviate(dict[a], ++pre[a]);
                }
            }
        }
        
        return res;
    }
    
    string abbreviate(string s, int k) {
        return (k >= s.size()-2) ? 
            s : s.substr(0, k) + to_string(s.size()-k-1) + s.back();
    }
