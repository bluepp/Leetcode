/*
  2015-09-20
  bluepp
  May the force be with me!
  
  Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest. 
  Your code should return the index of the first number and the index of the last number. 
  (If their are duplicate answer, return anyone. The answer can be rorate array or non- rorate array)
*/

/* my version, can not pass large, why ? */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        vector<int> res;
        int n = A.size();
        int sum = 0, maxsum = INT_MIN;
        int start = 0;
        
        for (int i = 0; i < n*2-1; i++)
        {
            int t = (i > n-1) ? A[i-n] : A[i];
           
            if (sum + t < t)
            {
                if (i > n-1) return res;
                
                sum = t;
                start = i;
            }
            else
            {
                sum += t;
            }
            
            if (sum > maxsum)
            {
                maxsum = sum;
                res = {start, (i > n-1) ? i-n : i};
            }
        }
        
        return res;
    }
