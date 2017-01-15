/*
bluepp
2017-01-16
May the force be with me!

https://leetcode.com/problems/matchsticks-to-square/

Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has,
please find out a way you can make one square by using up all those matchsticks. You should not break any stick,
but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will 
either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.

*/


    bool makesquare(vector<int>& nums) {
        
        if (nums.empty() || nums.size() < 4) return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        
        return _square(nums, sums, 0, sum/4);
    }
    
    bool _square(vector<int> &nums, vector<int> sums, int pos, int target)
    {
        if (pos >= nums.size())
        {
            return sums[0] == target && sums[1] == target && sums[2] == target;
        }
        
        for (int i = 0; i < 4; i++)
        {
            if (sums[i] + nums[pos] > target) continue;
            
            sums[i] += nums[pos];
            if (_square(nums, sums, pos+1, target)) return true;
            sums[i] -= nums[pos];
        }
        
        return false;
    }
