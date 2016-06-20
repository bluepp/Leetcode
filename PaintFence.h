/*
  2015-09-06
  bluepp
  May the force be with me!
  
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
https://leetcode.com/problems/paint-fence/
*/
/*
https://leetcode.com/discuss/56173/o-n-time-java-solution-o-1-space
*/

public int numWays(int n, int k) {
    if(n == 0) return 0;
    else if(n == 1) return k;
    int diffColorCounts = k*(k-1);
    int sameColorCounts = k;
    for(int i=2; i<n; i++) {
        int temp = diffColorCounts;
        diffColorCounts = (diffColorCounts + sameColorCounts) * (k-1);
        sameColorCounts = temp;
    }
    return diffColorCounts + sameColorCounts;
}


/*dp,  https://leetcode.com/discuss/56146/dynamic-programming-c-o-n-time-o-1-space-0ms */
    int numWays(int n, int k) {
        if (n <= 1 || k == 0) return n*k;
        
        int a = k, b = k*(k-1), c = 0, d = 0;
        for (int i = 2; i < n; i++)
        {
            d = (k-1)*(a+b);
            a = b;
            b = d;
        }
        
        return a+b;
    }
