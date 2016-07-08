/*
2016-07-09
bluepp
May the force be with me!

https://leetcode.com/problems/android-unlock-patterns/

Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
*/



   int numberOfPatterns(int m, int n) {
        
        return _count(m, n, 0, 1, 1);
    }
    
    int _count(int m , int n, int used, int i1, int j1)
    {
        int res = m <= 0;
        if (!n)
        {
            return 1;
        }
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int x = i1 + i, y = j1 + j, used2 = used | (1 << (i * 3 + j));
                
                if (used2 > used && (x % 2 || y % 2 || used2 & (1 << (x/2 * 3 + y/2))))
                {
                    res += _count(m-1, n-1, used2, i, j);
                }
            }
        }
        
        return res;
        
    }
