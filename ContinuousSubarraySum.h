/*
  2015-09-20
  bluepp
  May the force be with me!
  
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. 
our code should return the index of the first number and the index of the last number. 
(If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes
Example
Give [-3, 1, 3, -3, 4], return [1,4].
http://www.lintcode.com/en/problem/continuous-subarray-sum/#
*/

    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        
        vector<int> res;
        int n = A.size();
        int sum = 0, maxsum = INT_MIN;
        int start = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (sum+A[i] < A[i])
            {
                start = i;
                sum = A[i];
            }
            else
            {
                sum += A[i];
            }
            
            if (sum > maxsum)
            {
                res = {start, i};
                maxsum = sum;
            }
        }
        
        return res;
    }
