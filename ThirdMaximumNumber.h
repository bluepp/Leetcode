/*
bluepp
2016-11-07
May the force be with me!

https://leetcode.com/problems/third-maximum-number/

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/

    int thirdMax(vector<int>& nums) {
        
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        
        for (auto p : nums)
        {
            if (p > first)
            {
                third = second;
                second = first;
                first = p;
            }
            else if (p > second && p < first)
            {
                third = second;
                second = p;
            }
            else if (p > third && p < second)
            {
                third = p;
            }
        }
        
        return (third == LONG_MIN || third == second) ? first : third;
        
    }
