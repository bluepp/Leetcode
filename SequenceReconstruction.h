/* 
bluepp
2017-02-17
May the force be with me!

https://leetcode.com/problems/sequence-reconstruction/

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]

Output:
false

Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input:
org: [1,2,3], seqs: [[1,2]]

Output:
false

Explanation:
The reconstructed sequence can only be [1,2].
Example 3:

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]

Output:
true

Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input:
org: [4,1,5,2,6,3], seqs: [[5,2,6,3],[4,1,5,2]]

Output:
true
*/

    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        unordered_map<int, int> map, pre;
        
        for (int i = 0; i < org.size(); i++)
        {
            map[org[i]] = i;
        }
        
        for (auto seq : seqs)
        {
            for (int i = 0; i < seq.size(); i++)
            {
                if (!map.count(seq[i])) return false;
                if (i > 0 && map[seq[i]] < map[seq[i-1]]) return false;
                
                if (!pre.count(seq[i]))
                {
                    pre[seq[i]] = (i > 0) ? map[seq[i-1]] : -1;
                }
                else
                {
                    pre[seq[i]] = max(pre[seq[i]], (i > 0) ? map[seq[i-1]] : -1);
                }
                
            }
        }
        
        for (int i = 0; i < org.size(); i++)
        {
            if (pre[org[i]] != i-1) return false;
        }
        
        return true;
    }
