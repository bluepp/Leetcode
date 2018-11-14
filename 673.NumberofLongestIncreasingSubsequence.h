/*
Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
*/

    int findNumberOfLIS(vector<int>& nums) {
        int ret = 0, mx = 0;
        int n = nums.size();
        vector<int> len(n, 1), count(n, 1);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) {
                    continue;
                }
                
                if (len[i] == len[j]+1) {
                    count[i] += count[j];
                } else if (len[i] < len[j]+1){
                    len[i] = len[j]+1;
                    count[i] = count[j];
                }
            }
            
            if (mx == len[i]) {
                ret += count[i];
            } else if (mx < len[i]) {
                mx = len[i];
                ret = count[i];
            }
            
        }
    
        return ret; 
    }
