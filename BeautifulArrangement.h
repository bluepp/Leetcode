/*
bluepp
2017-03-27
May the force be with me!

https://leetcode.com/problems/beautiful-arrangement/#/description

Suppose you have N integers from 1 to N. 
We define a beautiful arrangement as an array that is constructed by these N numbers successfully 
if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
Note:
N is a positive integer and will not exceed 15.
Show Company Tags
Show Tags

*/

    int countArrangement(int N) {
        
        int res = 0;
        vector<int> visited(N + 1, 0);
        helper(N, visited, 1, res);
        
        return res;
    }
    
    void helper(int N, vector<int>& visited, int pos, int& res) {
        if (pos > N) {
            ++res; 
            return;
        }
        for (int i = 1; i <= N; ++i) {
            if (visited[i] == 0 && (i % pos == 0 || pos % i == 0)) {
                visited[i] = 1;
                helper(N, visited, pos + 1, res);
                visited[i] = 0;
            }
        }
    }
