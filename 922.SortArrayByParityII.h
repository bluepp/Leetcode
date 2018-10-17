/*
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
*/

    vector<int> sortArrayByParityII(vector<int>& A) {
       
        int n = A.size();
        vector<int> ret(n);
        int i = 0, j = 1;
        
        for (int k = 0; k < n; k++) {
            if (A[k] % 2 == 0) {
                ret[i] = A[k];
                i += 2;
            } else {
                ret[j] = A[k];
                j += 2;
            }
        }
        
        return ret;
    }
