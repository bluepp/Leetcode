/*
bluepp
2016-06-16
May the force be with me!

https://leetcode.com/problems/rearrange-string-k-distance-apart/

Given a non-empty string str and an integer k, 
rearrange the string such that the same characters are at least distance k from each other.

All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".

Example 1:
str = "aabbcc", k = 3

Result: "abcabc"

The same letters are at least distance 3 from each other.
Example 2:
str = "aaabc", k = 3 

Answer: ""

It is not possible to rearrange the string.
Example 3:
str = "aaadbbcc", k = 2

Answer: "abacabcd"

Another possible answer is: "abcabcda"

The same letters are at least distance 2 from each other.
*/

/* https://leetcode.com/discuss/108174/c-unordered_map-priority_queue-solution-using-cache  */

    string rearrangeString(string str, int k) {
        if(k == 0) return str;
        int length = (int)str.size(); 

        string res;
        unordered_map<char, int> dict;
        priority_queue<pair<int, char>> pq;

        for(char ch : str) dict[ch]++;
        for(auto it = dict.begin(); it != dict.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }

        while(!pq.empty()){
            vector<pair<int, char>> cache; //store used char during one while loop
            int count = min(k, length); //count: how many steps in a while loop
            for(int i = 0; i < count; i++){
                if(pq.empty()) return "";
                auto tmp = pq.top();
                pq.pop();
                res.push_back(tmp.second);
                if(--tmp.first > 0) cache.push_back(tmp);
                length--;
            }
            for(auto p : cache) pq.push(p);
        }
        return res;
    }

