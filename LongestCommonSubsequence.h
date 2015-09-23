/* 
  2015-09-23
  bluepp
  May the force be with me!
  
Given two strings, find the longest common subsequence (LCS).
Your code should return the length of LCS.

Have you met this question in a real interview? Yes
Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1
For "ABCD" and "EACB", the LCS is "AC", return 2.

http://www.lintcode.com/en/problem/longest-common-subsequence/#
*/

    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int n1 = A.length(), n2 = B.length();
        if (n1 == 0 || n2 == 0) return 0;
        vector<vector<int> > dp (n1+1, vector<int>(n2+1, 0));
        
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (A[i-1] == B[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[n1][n2];
    }
