/*
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]
*/

     vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = accumulate(A.begin(), A.end(), 0);
        int sum_b = 0;
        
        unordered_set<int> s;
        
        for (auto p : B) {
            sum_b += p;
            s.insert(p);
        }
        
        int diff = (sum_b - sum_a)/2;
        
        vector<int> res;
        for(auto p : A) {
            if (s.count(p+diff)) {
                res = {p, p+diff};
            }
        } 
        
        return res;
    }
