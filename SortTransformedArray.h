/* 
bluepp
2016-06-23
May the force be with me!

https://leetcode.com/problems/sort-transformed-array/

Given a sorted array of integers nums and integer values a, b and c. 
Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
*/

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        stack<int> s, aux;
        
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int t = a * nums[i]*nums[i] + b*nums[i]+ c;
            
            while (!s.empty() && s.top() < t)
            {
                int k = s.top();
                s.pop();
                aux.push(k);
            }
            
            s.push(t);
            
            while (!aux.empty())
            {
                int k = aux.top();
                aux.pop();
                s.push(k);
            }
        }
        
        vector<int> res;
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            res.push_back(t);
        }
        
        return res;
        
    }


/* https://leetcode.com/discuss/108831/java-o-n-incredibly-short-yet-easy-to-understand-ac-solution */

public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] sorted = new int[n];
        int i = 0, j = n - 1;
        int index = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            if (a >= 0) {
                sorted[index--] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[i++], a, b, c) : quad(nums[j--], a, b, c);
            } else {
                sorted[index++] = quad(nums[i], a, b, c) >= quad(nums[j], a, b, c) ? quad(nums[j--], a, b, c) : quad(nums[i++], a, b, c);
            }
        }
        return sorted;
    }

    private int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}
