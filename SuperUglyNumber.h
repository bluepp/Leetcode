/*
bluepp
2016-06-02
May the force be with me!

https://leetcode.com/problems/super-ugly-number/
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

   int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        vector<int> index(primes.size());
        ugly[0] = 1;
        
        for (int j = 1; j < n; j++)
        {
            int res = INT_MAX;
            
            for (int i = 0; i < primes.size(); i++)
            {
                res = min(res, primes[i] * ugly[index[i]]);
            }
            
            for (int i = 0; i < primes.size(); i++)
            {
                if (res == primes[i] * ugly[index[i]])
                {
                    index[i]++;
                }
            }
            
            ugly[j] = res;
        }
        
        return ugly[n-1];
        
    }
