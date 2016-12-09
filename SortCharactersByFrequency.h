/*
bluepp
2016-12-09
May the force be with me!

https://leetcode.com/problems/sort-characters-by-frequency/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

    string frequencySort(string s) {
        
        string res;
        unordered_map<char, int> map;
        
        for (auto p : s) map[p]++;
        
        priority_queue<pair<int, int>> q;
        for (auto it : map)
        {
            q.push({it.second, it.first});
        }
        
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            
            for (int i = 0; i < it.first; i++)
            {
                res += it.second;
            }
        }
        
        return res;
    }
