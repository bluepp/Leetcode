/* 
2015-05-20
bluepp
May the force be with me!

Repeated DNA Sequences Total Accepted: 15078 Total Submissions: 79671 My Submissions Question Solution 
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

https://leetcode.com/problems/repeated-dna-sequences/
*/

    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        map<int, int> m;
        map<char, int> mole;
        mole['A'] = 0; mole['C'] = 1;mole['G'] = 2; mole['T'] = 3;
        if (s.length() < 11) return res;
        int x = 0, i = 0, mask = (1 << 20)-1;
        
        for (;i < 10; i++)
        {
            x = (x <<2) | mole[s[i]];
        }
        
        m[x] = 1;
        for (; i < s.length(); i++)
        {
            x = mask & ((x << 2) | mole[s[i]]);
            
            if (++m[x] == 2) res.push_back(convert2str(x));
        }
        
        return res;
    }
    
    string convert2str(int x)
    {
        string res;
        
        for (int i = 0; i < 10; i++)
        {
            int k = x & 3;
            if (k == 0) res = 'A' + res;
            if (k == 1) res = 'C' + res;
            if (k == 2) res = 'G' + res;
            if (k == 3) res = 'T' + res;
            
            x = x >> 2;
        }
        
        return res;
    }
