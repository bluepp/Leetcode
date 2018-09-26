/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

Example 1:

Input: [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
*/

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        vector<vector<int>> m(n, vector<int>(n, INT_MIN));
        
        return _score(piles, 0, n-1, m) > 0;
    }
    
    int _score(vector<int> &piles, int l, int r, vector<vector<int>> &m) {
        if (l == r) {
            return piles[l];
        }
        
      
        if (m[l][r] == INT_MIN) {
             m[l][r] = max(piles[l] - _score(piles, l+1, r, m),
                     piles[r] - _score(piles, l, r-1, m));
        }
     
        
        return m[l][r];
    }
