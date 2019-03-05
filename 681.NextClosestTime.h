/*
Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

Example 1:

Input: "19:34"
Output: "19:39"
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
Example 2:

Input: "23:59"
Output: "22:22"
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
*/

    string nextClosestTime(string time) {
        
        string res = time;
        set<int> s{time[0], time[1], time[3], time[4]};
        string str(s.begin(), s.end());
        for (int i = res.size() - 1; i >= 0; --i) {
            if (res[i] == ':') continue;
            int pos = str.find(res[i]);
            if (pos == str.size() - 1) {
                res[i] = str[0];
            } else {
                char next = str[pos + 1];
                if (i == 4) {
                    res[i] = next;
                    return res;
                } else if (i == 3 && next <= '5') {
                    res[i] = next;
                    return res; 
                } else if (i == 1 && (res[0] != '2' || (res[0] == '2' && next <= '3'))) {
                    res[i] = next;
                    return res;
                } else if (i == 0 && next <= '2') {
                    res[i] = next;
                    return res;
                }
                res[i] = str[0];
            }
        }
        
        return res;
        
    }
