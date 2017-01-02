/*
bluepp
2017-01-03
May the force be with me!

https://leetcode.com/problems/reconstruct-original-digits-from-english/

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/

    string originalDigits(string s) {
        
        string res = "";
        vector<string> words{"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        vector<int> nums{0, 2, 4, 6, 8, 1, 3, 5, 7, 9}, counts(26, 0);
        vector<char> chars{'z', 'w', 'u', 'x', 'g', 'o', 'h', 'f', 's', 'i'};
        
        for (char c : s) ++counts[c - 'a'];
        for (int i = 0; i < 10; ++i) {
            int cnt = counts[chars[i] - 'a'];
            for (int j = 0; j < words[i].size(); ++j) {
                counts[words[i][j] - 'a'] -= cnt;
            }
            while (cnt--) res += (nums[i] + '0');
        }
        sort(res.begin(), res.end());
        return res;
        
    }
    
    
    string originalDigits(string s) {
        string res = "";
        vector<int> counts(128, 0), nums(10, 0);
        for (char c : s) ++counts[c];
        nums[0] = counts['z'];
        nums[2] = counts['w'];
        nums[4] = counts['u'];
        nums[6] = counts['x'];
        nums[8] = counts['g'];
        nums[1] = counts['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = counts['h'] - nums[8];
        nums[5] = counts['f'] - nums[4];
        nums[7] = counts['s'] - nums[6];
        nums[9] = counts['i'] - nums[6] - nums[8] - nums[5];
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                res += (i + '0');
            }
        }
        return res;
    }
