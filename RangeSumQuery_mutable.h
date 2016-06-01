/*
bluepp
2016-06-01
May the force be with me!

https://leetcode.com/problems/range-sum-query-mutable/
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

*/

class NumArray {
private:
    vector<int> vec;
    
public:
    NumArray(vector<int> &nums) {
        vec = nums;
    }

    void update(int i, int val) {
        vec[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        
        for (int tt = i; tt <= j; tt++)
        {
            sum += vec[tt];
        }
        
        return sum;
    }
};
