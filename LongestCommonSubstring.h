/*
  2015-09-24
  bluepp
  May the force be with me!
  
Longest Common Substring Show result 
Given two strings, find the longest common substring.
Return the length of it.

Have you met this question in a real interview? Yes
Example
Given A = "ABCD", B = "CBCE", return 2.

Note
The characters in substring should occur continuously in original string. This is different with subsequence.

Challenge
O(n x m) time and memory.
http://www.lintcode.com/en/problem/longest-common-substring/#

1. dp
2. O(n*m)
*/

/* dp */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int n1 = A.size(), n2 = B.size();
        vector<vector<int>> dp (n1+1, vector<int> (n2+1, 0));
        int ret = 0;
        
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                
                ret = max(ret, dp[i][j]);
            }
        }
        
        return ret;
    }
    
    /* 解法2：状态转移方程只涉及相邻状态，所以照例把空间优化成O(M)。 */
    /* http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=138272&page=6#pid1947603 */
    
   int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int n1 = A.size(), n2 = B.size();
        if (n1 == 0 || n2 == 0) return 0;
        
        vector<vector<int> > dp(2, vector<int> (n2+1, 0));
        int ret = 0;
        int f = 1; 
        int nf = !f;
        
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (A[i-1] == B[j-1])
                {
                    dp[f][j] = dp[nf][j-1]+1;
                }
                else 
                {
                    dp[f][j] = 0;
                }
                
                ret = max(ret, dp[f][j]);
            }
            
            f = !f;
            nf = !nf;
        }
        
        return ret;
    }    

