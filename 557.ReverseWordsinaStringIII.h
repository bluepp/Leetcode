/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

    string reverseWords(string s) {
        string res = "", t = "";
        istringstream is(s);
        
        while (is >> t) {
            reverse(t.begin(), t.end());
            res += t + " ";
        }
        
        res.pop_back();
        return res;
    }
