/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
*/

    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n <= 2) {
            return true;
        }
        
        
        bool isInc = false;
        bool isDec = false;
        if (A[1] >= A[0]) {
            isInc = true;
        } 
        if (A[1] <= A[0]) {
            isDec = true;
        }
        
        
        for (int i = 1; i < n; i++) {
            
            if (isInc && isDec) {
                if (A[i] > A[i-1]) {
                    isDec = false;
                }
                
                if (A[i] < A[i-1]) {
                    isInc = false;
                }
            }
            
            if (isInc && A[i] < A[i-1]) {
                return false;
            }
            
            if (isDec && A[i] > A[i-1]) {
                return false;
            }
            
        }
        
        return true;
        
    }



/* ------------------------------------------------------- */


5
6
7
8
9
10
11
12
13
14
15
// Author: Huahua

  bool isMonotonic(vector<int>& A) {
    bool inc = true;
    bool dec = true;
    
    for (int i = 1; i < A.size(); ++i) {
      inc &= A[i] >= A[i - 1];
      dec &= A[i] <= A[i - 1];
    }
    
    return inc || dec;
  }
