/*
bluepp
2017-01-02
May the force be with me!

https://leetcode.com/problems/4sum-ii/

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/

/*1 hash*/
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        int ret = 0;
        unordered_map<int, int> map;
        
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                map[A[i]+B[j]]++;
            }
        }
        
        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                int t = -(C[i]+D[j]);
                ret += map[t];
            }
        }
        
        return ret;

    }
    
    
    
    
  /* 2 hash */  
    
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        int ret = 0;
        int n = A.size();
        unordered_map<int, int> m1, m2;
        
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                m1[A[i]+B[j]]++;
                m2[C[i]+D[j]]++;
            }
        }
        
        for (auto it : m1)
        {
            ret += it.second * m2[-it.first];
        }
        
        return ret;
    }
