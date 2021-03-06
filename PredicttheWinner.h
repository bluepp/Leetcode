/*
bluepp
2018-02-16
May the force be with me!

https://leetcode.com/problems/predict-the-winner/

Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return False.
Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
*/

/* 2017-03-16, another one */
    bool PredictTheWinner(vector<int>& nums) {
        
        return canwin(nums, 0, 0, 1);
    }
    
    bool canwin(vector<int>& nums, int sum1, int sum2, int player)
    {
        if (nums.empty()) return sum1 >= sum2;
        
        if (nums.size() == 1)
        {
            if (player == 1) return sum1+nums[0] >= sum2;
            else if (player == 2) return sum1+nums[0] < sum2;
        }
        
        vector<int> va = vector<int>(nums.begin()+1, nums.end());
        vector<int> vb = vector<int>(nums.begin(), nums.end()-1);
        
        if (player == 1)
        {
            return !canwin(va, sum1+nums[0], sum2, 2) || !canwin(vb, sum1+nums.back(), sum2, 2);
        }
        else if (player == 2)
        {
            return !canwin(va, sum1, sum2+nums[0], 1) || !canwin(vb, sum1, sum2+nums.back(), 1);
        }
        
    }




    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return canwin(nums, 0, n-1, dp) >= 0;
    }
    
    int canwin(vector<int> &nums, int s, int e, vector<vector<int>> &dp)
    {
        if (dp[s][e] == -1)
        {
            dp[s][e] = (s == e) ? nums[s] : 
                max(nums[s]-canwin(nums, s+1, e, dp), nums[e]-canwin(nums, s, e-1, dp));
        }
        
        return dp[s][e];
    }
