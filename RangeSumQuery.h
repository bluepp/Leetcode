/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/range-sum-query-immutable/
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
private:
    vector<int> vec;
    
public:
    NumArray(vector<int> &nums) {
        vec = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        
        for (int t = i; t <= j; t++)
        {
            sum += vec[t];
        }
        
        return sum;
    }
};
