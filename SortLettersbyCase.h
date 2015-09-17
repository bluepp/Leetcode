/*
  2015-09-18
  bluepp
  May the force be with me!


Given a string which contains only letters. Sort it by lower case first and upper case second.
Example
For "abAcD", a reasonable answer is "acbAD"
*/

    void sortLetters(string &letters) {
        // write your code here
        int n = letters.size();
        if (n == 0) return;
        
        int l = 0, r = n-1;
        while (l < r)
        {
            while (l < r && letters[l] >= 'a' && letters[l] <= 'z') l++;
            while (l < r && letters[r] >= 'A' && letters[r] <= 'Z') r--;
            
            swap(letters[l], letters[r]);
        }
    }
