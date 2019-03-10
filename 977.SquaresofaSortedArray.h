/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, 0);
        
        int start = 0, end = n-1;
        
        for(int i = n-1; i >= 0; i--){
            if (abs(A[start]) > abs(A[end])){
                res[i] = A[start]*A[start];
                start++;
            } else {
                res[i] = A[end] * A[end];
                end--;
            }
        }
        
        return res;
        
    }
