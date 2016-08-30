/*
2016-08-30
bluepp
May the force be with me!

https://leetcode.com/problems/shuffle-an-array/

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
private:
    vector<int> v;
    
    
public:
    Solution(vector<int> nums) {
        
        v = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return v;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        vector<int> res = v;
        
        for (int i = 0; i < res.size(); i++)
        {
            int t = rand() % res.size();
            swap(res[i], res[t]);
        }
        
        return res;
    }
};
