/*
bluepp
2016-11-07
May the force be with me!

https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
*/

   int findMaximumXOR(vector<int>& nums) {
        
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
