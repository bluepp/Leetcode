/*
  bluepp
  2014-07-27
  May the force be with me!
  
 Problem:    ZigZag Conversion
 Source:     http://leetcode.com/onlinejudge#question_6
 Notes:
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Solution: ...
 */

/* Do not understand !!! */

    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string res;
        int inc = (nRows -1) * 2, N = s.size();
        
        for (int i = 0; i < nRows; i++)
        {
            int j = 0;
            while (true)
            {
                if (i > 0 && i < nRows-1 && j-i >= 0 && j-i < N)
                {
                    res.push_back(s[j-i]);
                }
                if (j+i < N)
                {
                    res.push_back(s[j+i]);
                }
                if (j+i >= N)
                {
                    break;
                }
                
                j += inc;
            }
        }
        
        return res;
        
    }
