/*
    bluepp
    2014-06-18
    2014-07-19
    2014-08-23
    
    May the force be with me!
    
    Problem:    Pascal's Triangle II
    Source:     https://oj.leetcode.com/problems/pascals-triangle-ii/
    Notes:
    Given an index k, return the kth row of the Pascal's triangle.
    For example, given k = 3,
    Return [1,3,3,1].
    Note:
    Could you optimize your algorithm to use only O(k) extra space?

    Solution: from back to forth...
 */
 
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        
        for (int i = 1; i < rowIndex+1; i++)
        {
            for (int j = i-1; j >= 1 ; j--)
            {
                res[j] += res[j-1];
            }
        }
        
        return res;
        
    }
