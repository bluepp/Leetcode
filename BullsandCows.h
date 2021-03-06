/*
  2015-11-02
  bluepp
  May the force be with me!
  
You are playing the following Bulls and Cows game with your friend:
You write a 4-digit secret number and ask your friend to guess it. 
Each time your friend guesses a number, you give a hint.
The hint tells your friend how many digits are in the correct positions (called "bulls")
and how many digits are in the wrong positions (called "cows").
Your friend will use those hints to find out the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess,
use A to indicate the bulls and B to indicate the cows.
In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

https://leetcode.com/problems/bulls-and-cows/
*/

/* 2016-07-02, anoter one, my version */

    string getHint(string secret, string guess) {
        
        unordered_map<int, int> map;
        int bulls = 0, cow = 0;
        
        int n = secret.size();
        
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                bulls ++;
            }
            else
            {
                map[secret[i]]++;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if (secret[i] != guess[i] && map[guess[i]])
            {
                cow++;
                map[guess[i]]--;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cow) + "B";
    }



/* 2016-07-01, easy understanding one */

    string getHint(string secret, string guess) {
        
        int m[256] = {0}, bulls = 0, cows = 0;
        
        for (int i = 0; i < secret.size(); ++i) {
            
            if (secret[i] == guess[i]) ++bulls;
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++ cows;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
        
    }



    string getHint(string secret, string guess) {
        int m[256] = {0}, a = 0, b = 0, i = 0;
        for (char s : secret) {
            char g = guess[i++];
            a += s == g;
            b += (m[s]++ < 0) + (m[g]-- > 0);
        }
        return to_string(a) + "A" + to_string(b - a) + "B";
    }
