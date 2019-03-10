/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

    vector<int> sortArrayByParity(vector<int>& A) {
        
        int n = A.size();
        vector<int> even, odd;
        
        for (auto p : A) {
            if (p % 2) {
                odd.push_back(p);
            } else {
                even.push_back(p);
            }
        }
        
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }

/* ------------------------------------------------- */
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int l = 0, r = A.size()-1;
        
        while (l < r) {
            while (l < r && A[l]%2 == 0) {
                l++;
            }
            
            while (l < r && A[r]%2 == 1) {
                r--;
            }
            
            swap(A[l], A[r]);
        }
        
        return A;
      
    }
