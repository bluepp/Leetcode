/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

*/

    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        
        for (auto p : nums) {
            if (m1 >= p) {
                m1 = p;
            } else if (m2 >= p) {
                m2 = p;
            } else {
                return true;
            }
        }
        
        return false; 
    }


/* ---------------------------------------------------- */
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        
        vector<int> f(n, nums[0]), b(n, nums.back());
        
        for (int i = 1; i < n; i++) {
            f[i] = min(f[i-1], nums[i]);
        }
        
        for (int i = n-2; i >= 0; i--) {
            b[i] = max(b[i+1], nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > f[i] && nums[i] < b[i]) {
                return true;
            }
        }
        
        return false;
    }
