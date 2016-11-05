/*
bluepp
2016-11-05
May the force be with me!

https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

*/

    int romanToInt(string s) {
        
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for (int i = 0; i < s.size(); ++i) {
            
            int val = m[s[i]];
            if (i == s.size() - 1 || m[s[i+1]] <= m[s[i]]) res += val;
            else res -= val;
        }
        
        return res;
    }
