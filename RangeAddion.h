/*
2016-07-06
bluepp
May the force be with me!

https://leetcode.com/problems/range-addition/

Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
Show Hint 


*/

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1);
        for (auto a : updates) {
            res[a[0]] += a[2];
            res[a[1] + 1] -= a[2];
        }
        for (int i = 1; i < res.size(); ++i) {
            res[i] += res[i - 1];
        }
        res.pop_back();
        return res;
    }
