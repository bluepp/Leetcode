/*
  2015-06-15
  bluepp
  May the force be with me!
  
Description:
Count the number of prime numbers less than a non-negative number, n.
https://leetcode.com/problems/count-primes/
*/

    int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1;
        bool *prime = (bool *)malloc(sizeof(bool) * n);
        int i = 0, j = 0;
        int count = n-2;
        int r = sqrt(n);
        
        for (j = 0; j < n; j++)
        {
            prime[j] = 1;
        }
        
        for (i = 2; i <= r; i++)
        {
            if (prime[i])
            {
                for (j = i*2; j < n; j += i)
                {
                    if (prime[j])
                    {
                        prime[j] = 0;
                        count--;
                    }
                }
            }
        }
        
        free(prime);
        return count;
    }
  
