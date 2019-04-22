/*
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[B.length - 1]
 

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 
 */
 
     bool validMountainArray(vector<int>& A) {
        
        if (A.size() < 3){
            return false;
        }
        
        int n = A.size();
        
        if (A[1] <= A[0] || A[n-2] <= A[n-1]){
            return false;
        }
      
        bool down = false;
        for (int i = 1; i < n; i++){
            if (A[i] == A[i-1]){
                return false;
            }
            
            if (!down && (A[i] < A[i-1])){
                down = true;
            }
            
            if (down && A[i] > A[i-1]){
                return false;
            }
        }
        
        return true;

    }
