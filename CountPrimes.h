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
        
        int count = n-2;
        bool prime[n];
        
        for (int i = 0; i < n; i++)
        {
            prime[i] = true;
        }
        
        int r = sqrt(n);
        for (int i = 2; i <= r; i++)
        {
            if (prime[i])
            {
                for (int j = i*2; j < n; j += i)
                {
                    if (prime[j])
                    {
                        prime[j] = false;
                        count --;
                    }
                }
            }
        }
        
        return count;
        
    }
  
