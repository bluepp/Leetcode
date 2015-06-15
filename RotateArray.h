/*
  2015-06-15
  bluepp
  May the force be with me!
  
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II
https://leetcode.com/problems/rotate-array/
*/

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        if(k == 0)
            return ;

        int g = gcd(n, k);
        if(g == 1){
            change_array(nums, 0, k, n);
        }else{
            int i;
            for(i=0; i<g; i++){
                change_array(nums, i, k, n/g);
            }
        }
    }
    
    void change_array(vector<int>& nums, int start, int k, int times){
        int curr = start;
        int n = nums.size();
        int last = nums[start];
        
        while(times--){
            int next = (curr + k) % n;
            int tmp = nums[next];
            nums[next] = last;
            curr = next;
            last = tmp;
        }
    }

    int gcd(int a, int b){
        while(b != 0){
            int r = b;
            b = a % b;
            a = r;
        }
        return a;
    }
