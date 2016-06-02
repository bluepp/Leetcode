/*
bluepp
2016-06-02
May the force be with me!

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

Show Company Tags
Show Tags
Show Similar Problems

*/


/* https://leetcode.com/discuss/80933/simple-solution-complexity-analysis-exponential-factorial */

    bool canWin(string s) {
        
        int t = s.length();
        for (int i = 0; i < t-1; i++)
        {
            if (s[i] == '-' || s[i+1] == '-')
            {
                continue;
            }
            
            s[i] = '-';
            s[i+1] = '-';
            
            bool otherwin = canWin(s);
            
            s[i] = '+';
            s[i+1] = '+';
            
            if (!otherwin) return true;
        }
        
        return false;
    }
