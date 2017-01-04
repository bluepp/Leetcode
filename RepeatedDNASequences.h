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


/* 2017-01-05, update , simple one */
    vector<string> findRepeatedDnaSequences(string s) {
        
        set<string> res, st;
        
        for (int i = 0; i + 9 < s.size(); ++i) {
            
            string t = s.substr(i, 10);
            if (st.count(t)) res.insert(t);
            else st.insert(t);
        }
        
        return vector<string>{res.begin(), res.end()};
        
    }


/*2015-01-07, update */
   vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        
        while (i < s.size()) {
            
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        
        return vector<string>(res.begin(), res.end());
        
    }




/* 2016-07-19, update */
/* 2016-08-01, minor update, easy understanding */
   vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        int n = s.length();
        if (n <= 10)
        {
            return res;
        }
        
        int mask = 0x7ffffff;
        unordered_map<int, int> map;
        
        int i = 0;
        int curr = 0;
        
        while (i < 10)
        {
            curr = (curr << 3) | (s[i++] & 0x7);
        }
        
        map[curr] = 1;
        
        while (i < n)
        {
            curr = ((curr & mask) << 3 | s[i++] & 0x7);
            
            if (map.count(curr))
            {
                if (map[curr] == 1)
                {
                    res.push_back(s.substr(i-10, 10));
                }
                
                map[curr]++;
            }
            else
            {
                map[curr] = 1;
            }
        }
        
        return res;
    }


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
