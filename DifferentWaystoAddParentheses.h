/* 
  2015-08-13
  bluepp
  May the force be with me!
  
Given a string of numbers and operators, return all possible results from computing all the different possible ways to 
group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

https://leetcode.com/problems/different-ways-to-add-parentheses/
*/

/* 2016-07-18, update */
    vector<int> diffWaysToCompute(string input) {
        
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
            
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }

        if (res.empty()) res.push_back(stoi(input));
        
        return res;
    }


/* https://leetcode.com/discuss/49879/c-solution-using-dp-easy-understanding */
/* OMG!!! */
    vector<int> diffWaysToCompute(string input) {
        vector<int> data;
        vector<char> ops;
        
        int num = 0;
        char op = ' ';
        
        istringstream ss(input + "+");
        while(ss >> num && ss >> op) {
            data.push_back(num);
            ops.push_back(op);
        }
        
        const int size_i = data.size();
        vector<vector<vector<int>>> dp(size_i, vector<vector<int>>(size_i, vector<int>()));
    
        for (int i = 0; i < size_i; i += 1)
            for (int j = i; j >= 0; j -= 1) {
                if (i == j) {dp[j][i].push_back(data[i]); continue;}
                    for (int k = j; k < i; k += 1) {
                        for (auto left : dp[j][k]) 
                            for (auto right : dp[k+1][i]) {
                                int val = 0;
                                switch(ops[k]) {
                                    case '+': val = left + right; break;
                                    case '-': val = left - right; break;
                                    case '*': val = left * right; break;
                                }
                                dp[j][i].push_back(val);
                            }
                    }
        }
        
        return dp[0][size_i-1];
    }
